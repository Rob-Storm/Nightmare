#include "Inventory/ItemSlot.h"

#include "Inventory/Item.h"

void UItemSlot::SetSlotItem(UItem* Item)
{
	SlotItem = Item;
	OnSlotItemChanged.Broadcast(SlotItem);
}

bool UItemSlot::IsTopLeftSlot(FIntPoint SlotPosition)
{
	return SlotItem->ItemLocation == SlotPosition;
}