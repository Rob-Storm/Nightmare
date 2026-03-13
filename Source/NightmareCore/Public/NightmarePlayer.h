#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Inventory/InventoryComponent.h"

#include "NightmarePlayer.generated.h"

UCLASS()
class ANightmarePlayer : public ACharacter
{
	GENERATED_BODY()

public:

	ANightmarePlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UInventoryComponent> InventoryComponent;
	
};
