#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "Inventory/ItemData.h"

#include "WorkbenchRecipes.generated.h"

USTRUCT(BlueprintType)
struct FWorkbenchRecipe : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recipe")
	TObjectPtr<UItemData> ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recipe")
	int32 ScrapCost = 0;

	/** How much should the cost increase by after each purchase? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recipe")
	int32 IncreaseFactor = 0;

	/** Used for items you do not want the player to have multiple of (e.g. weapons, radio, etc.) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recipe")
	bool OneAllowed = false;

};