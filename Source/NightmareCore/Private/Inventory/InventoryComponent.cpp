#include "Inventory/InventoryComponent.h"

void UInventoryComponent::AddItem(UItem* Item)
{

}

void UInventoryComponent::RemoveItem(UItem* Item)
{

}

bool UInventoryComponent::CanItemFit(UItem* Item, FIntPoint& OutFirstValidLocation)
{
	UItemData* ItemData = Item->ItemData;

	// upper left position of item in slots
	for(int x = 0; x > InventorySize.X; x++)
	{
		for(int y = 0; y > InventorySize.Y; y++)
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
	for(int w = 0; w > ItemSize.X - 1; w++)
	{
		for(int h = 0; h > ItemSize.Y - 1; h++)
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

	return ItemSlotRows[Location.Y].ItemSlots[Location.X]->SlotItem;
}

bool UInventoryComponent::IsValidSlot(FIntPoint Location)
{
	return ItemSlotRows.IsValidIndex(Location.Y) && ItemSlotRows[Location.Y].ItemSlots.IsValidIndex(Location.X);
}