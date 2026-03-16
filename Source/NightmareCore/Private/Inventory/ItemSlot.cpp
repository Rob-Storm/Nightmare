#include "Inventory/ItemSlot.h"

#include "Inventory/Item.h"

bool UItemSlot::IsTopLeftSlot(FIntPoint SlotPosition)
{
	return SlotItem->ItemLocation == SlotPosition;
}