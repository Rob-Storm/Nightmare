#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "ItemSlot.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FItemSlotArray
{
	GENERATED_BODY()

public:

	TArray<UItemSlot*> ItemSlots;
};

UCLASS()
class UItemSlot : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item Slot")
	TObjectPtr<class UItem> SlotItem;
};
