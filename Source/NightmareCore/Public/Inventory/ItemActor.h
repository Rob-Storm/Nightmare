#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"

#include "Interactable.h"
#include "Inventory/ItemData.h"

#include "ItemActor.generated.h"

UCLASS()
class AItemActor : public AActor, public IInteractable
{
	GENERATED_BODY()

public:

	AItemActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> Model;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ItemActor")
	TObjectPtr<UItemData> ItemData;

	virtual void Interact_Implementation(class ACharacter* CallingCharacter) override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	
};
