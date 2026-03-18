#include "Inventory/InventoryComponent.h"
#include "UObject/Object.h"

#include "Inventory/ItemData.h"
#include "Inventory/ItemActor.h"

void UInventoryComponent::BeginPlay()
{
	ItemSlotRows.Empty();
	ItemSlotRows.SetNum(InventorySize.Y);

	ItemList.Empty();

	for(int32 rowIndex = 0; rowIndex < InventorySize.Y; rowIndex++)
	{
		FItemSlotArray& Row = ItemSlotRows[rowIndex];
		Row.SlotsRow.SetNum(InventorySize.X);

		for(int32 slotIndex = 0; slotIndex < InventorySize.X; slotIndex++)
		{
			Row.SlotsRow[slotIndex] = NewObject<UItemSlot>(this);
		}
	}
}

void UInventoryComponent::AddItem(UItemData* ItemData, FIntPoint Location)
{
	if(!ItemData)
	{
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Added Item ") + ItemData->ItemName.ToString() + Location.ToString());

	UItem* NewItem = NewObject<UItem>(this);
	NewItem->ItemData = ItemData;

	ItemList.Add(NewItem);

	SetSlotItemLocation(NewItem, Location);

	OnInventoryChanged.Broadcast();
}

void UInventoryComponent::RemoveItem(UItem* Item)
{
	if(!Item)
	{
		return;
	}

	int32 RemoveItemIndex = ItemList.Find(Item);

	if(RemoveItemIndex == -1)
	{
		return;
	}

	ItemList.RemoveAt(RemoveItemIndex);

	// todo: set the slots the item occupied to nullptr

	ClearCells(Item->ItemLocation, Item->ItemData->ItemSize);

	OnInventoryChanged.Broadcast();
}

void UInventoryComponent::SpawnItemActor(UItem* Item)
{
	if(!Item)
	{
		return;
	}

	FVector SpawnLocation = FVector(0.f, 0.f, 100.f);
	FRotator SpawnRotation = FRotator::ZeroRotator;

	AItemActor* SpawnedItemActor = GetWorld()->SpawnActor<AItemActor>(AItemActor::StaticClass(), SpawnLocation, SpawnRotation);
	SpawnedItemActor->SetItemData(Item->ItemData);

}

bool UInventoryComponent::CanItemFit(class UItemData* ItemData, FIntPoint& OutFirstValidLocation)
{
	// upper left position of item in slots
	for(int32 x = 0; x < InventorySize.X; x++)
	{
		for(int32 y = 0; y < InventorySize.Y; y++)
		{
			if(CanItemFitAtLocation(ItemData->ItemSize, FIntPoint(x, y)))
			{
				OutFirstValidLocation = FIntPoint(x, y);
				return true;
			}
			else
			{
				continue;
			}
		}
	}

	return false;
}

bool UInventoryComponent::CanItemFitAtLocation(FIntPoint ItemSize, FIntPoint Location)
{
	// item width and height
	for(int32 w = 0; w < ItemSize.X - 1; w++)
	{
		for(int32 h = 0; h < ItemSize.Y - 1; h++)
		{
			// Item is probably at the edge and the size is greater than 1 on either axis
			if(!IsValidSlot(FIntPoint(Location.Y + h, Location.X + w)))
			{
				return false;
			}

			// IsValid means an item is occupying the slot
			if(IsValid(GetItemFromSlot(FIntPoint(Location.Y + h, Location.X + w))))
			{
				return false;
			}
		}
	}

	return true;
}

UItem* UInventoryComponent::GetItemFromSlot(FIntPoint Location)
{
	if(!IsValidSlot(FIntPoint(Location.Y, Location.X)))
	{
		return nullptr;
	}

	return ItemSlotRows[Location.Y].SlotsRow[Location.X]->SlotItem;
}

bool UInventoryComponent::IsValidSlot(FIntPoint Location)
{
	return ItemSlotRows.IsValidIndex(Location.Y) && ItemSlotRows[Location.Y].SlotsRow.IsValidIndex(Location.X);
}

void UInventoryComponent::SetSlotItemLocation(UItem* Item, FIntPoint Location)
{
	UItemData* Data = Item->ItemData;
	Item->ItemLocation = Location;

	if(!IsValidSlot(Location))
	{
		return;
	}

	for(int32 x = 0; x < Data->ItemSize.X; x++)
	{
		for(int32 y = 0; y < Data->ItemSize.Y; y++)
		{
			SetCellItem(Item, FIntPoint(x, y) + Item->ItemLocation);
		}
	}

}

void UInventoryComponent::SetCellItem(UItem* Item, FIntPoint Location)
{
	if(!IsValidSlot(Location))
	{
		return;
	}

	ItemSlotRows[Location.Y].SlotsRow[Location.X]->SetSlotItem(Item);
}

void UInventoryComponent::ClearCells(FIntPoint OldLocation, FIntPoint OldSize)
{
	for(int32 x = 0; x < OldSize.X; x++)
	{
		for(int32 y = 0; y < OldSize.Y; y++)
		{
			SetCellItem(nullptr, FIntPoint(x, y) + OldLocation);
		}
	}
}