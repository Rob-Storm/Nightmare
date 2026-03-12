#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "NightmarePlayerState.generated.h"

UCLASS()
class ANightmarePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player State")
	int32 CurrentScrap;

	UFUNCTION(BlueprintCallable, Category="Player State")
	void AddScrap(int32 Amount)
	{
		CurrentScrap += Amount;
	}

};