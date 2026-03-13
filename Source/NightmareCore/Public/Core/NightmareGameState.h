#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"

#include "NightmareGameState.generated.h"

UCLASS()
class ANightmareGameState : public AGameState
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game State")
	int32 CurrentHour = 0;
	
};
