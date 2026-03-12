#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Interactable.generated.h"

UINTERFACE()
class NIGHTMARECORE_API UInteractable : public UInterface
{
	GENERATED_BODY()
};

class NIGHTMARECORE_API IInteractable
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interactable")
	void Interact(class ACharacter* CallingCharacter);
	void Interact_Implementation(class ACharacter* CallingCharacter);
	
};