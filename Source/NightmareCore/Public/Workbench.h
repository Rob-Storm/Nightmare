#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"

#include "Workbench.generated.h"

UCLASS()
class AWorkbench : public AActor
{
	GENERATED_BODY()

public:

	AWorkbench();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> Model;
	
};
