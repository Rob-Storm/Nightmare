#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Inventory/InventoryComponent.h"

#include "WorkbenchRecipes.h"

#include "NightmarePlayer.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ANightmarePlayer : public ACharacter
{
	GENERATED_BODY()

public:

	ANightmarePlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UInventoryComponent> InventoryComponent;

	UFUNCTION(BlueprintCallable, Category="Recipe")
	bool CanBuyRecipe(const FWorkbenchRecipe& Recipe) const;
	
};