#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "NightmarePlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScrapChangedSignature, int32, Scrap);

UCLASS()
class ANightmarePlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category="Player State")
	FOnScrapChangedSignature OnScrapChanged;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player State")
	int32 CurrentScrap;

	UFUNCTION(BlueprintCallable, Category="Player State")
	void AddScrap(int32 Amount)
	{
		CurrentScrap += Amount;

		OnScrapChanged.Broadcast(CurrentScrap);
	}

};