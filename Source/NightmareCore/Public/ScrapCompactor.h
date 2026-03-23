#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/AudioComponent.h"

#include "Interactable.h"

#include "ScrapCompactor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProductionTickedSignature, int32, CurrentScrap, int32, MaxScrap);

UCLASS(BlueprintType, Blueprintable)
class AScrapCompactor : public AActor, public IInteractable
{
	GENERATED_BODY()

public:

	AScrapCompactor();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category="Compactor")
	FOnProductionTickedSignature OnProductionTicked;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UTextRenderComponent> ScrapText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> Model;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UAudioComponent> AudioComponent;
	
	UPROPERTY(ReplicatedUsing = OnRep_CurrentScrap, EditAnywhere, BlueprintReadWrite, Category="Compactor")
	int32 CurrentScrap = 0;

	UPROPERTY(ReplicatedUsing = OnRep_MaxScrap, EditAnywhere, BlueprintReadWrite, Category="Compactor")
	int32 MaxScrap = 1000;

	/** How many seconds between each production tick */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Compactor")
	float ProduceTickRate = 25.f;

	/** How much scrap is produced each tick */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Compactor")
	int32 ProduceAmount = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Compactor")
	TObjectPtr<USoundBase> ProduceSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Compactor")
	TObjectPtr<USoundBase> CollectSound;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Compactor")
	void Server_ScrapProductionTick();
	void Server_ScrapProductionTick_Implementation();

	UFUNCTION(BlueprintCallable, Category="Compactor")
	void UpdateText();

	UFUNCTION(BlueprintCallable, Category="Compactor")
	FString GetScrapString() const
	{
		return FString::FromInt(CurrentScrap) + TEXT(" / ") + FString::FromInt(MaxScrap);
	};

	virtual void Interact_Implementation(class ANightmarePlayerController* CallingController) override;


private:

	UPROPERTY()
	FTimerHandle ProductionTimerHandle;

	UFUNCTION() void OnRep_CurrentScrap();
	UFUNCTION() void OnRep_MaxScrap();

};
