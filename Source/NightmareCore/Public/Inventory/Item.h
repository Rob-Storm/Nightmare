#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "Inventory/ItemData.h"

#include "Item.generated.h"

/** Item representation in inventory */

UCLASS(Blueprintable, BlueprintType)
class UItem : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FIntPoint ItemLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	TObjectPtr<UItemData> ItemData;

};