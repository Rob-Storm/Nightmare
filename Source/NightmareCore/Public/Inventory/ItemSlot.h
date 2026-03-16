#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "ItemSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotItemChangedSignature, UItem*, SlotItem);

USTRUCT(Blueprintable, BlueprintType)
struct FItemSlotArray
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemSlotArray")
	TArray<UItemSlot*> SlotsRow;
	
};

UCLASS(Blueprintable, BlueprintType)
class UItemSlot : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category="Item Slot")
	FOnSlotItemChangedSignature OnSlotItemChanged;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Slot")
	TObjectPtr<class UItem> SlotItem;

	UFUNCTION(BlueprintCallable, Category="Item Slot")
	void SetSlotItem(class UItem* Item)
	{
		SlotItem = Item;

		OnSlotItemChanged.Broadcast(SlotItem);
	}

	UFUNCTION(BlueprintCallable, Category="Item Slot")
	bool IsTopLeftSlot(FIntPoint SlotPosition);
};