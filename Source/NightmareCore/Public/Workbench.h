#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"

#include "Interactable.h"

#include "Workbench.generated.h"

UCLASS()
class AWorkbench : public AActor, public IInteractable
{
	GENERATED_BODY()

public:

	AWorkbench();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> Model;

	virtual void Interact_Implementation(class ANightmarePlayerController* CallingController) override;
	
};
