#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "NightmareGameMode.generated.h"

UCLASS()
class ANightmareGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Mode")
	int32 MaxHour = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Mode")
	TArray<int32> BossRounds;
	
};
