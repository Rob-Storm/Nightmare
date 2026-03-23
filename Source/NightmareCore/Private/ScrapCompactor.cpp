#include "ScrapCompactor.h"
#include "UObject/Object.h"
#include "Net/UnrealNetwork.h"

#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

#include "NightmarePlayer.h"
#include "Core/NightmarePlayerController.h"
#include "Core/NightmarePlayerState.h"

AScrapCompactor::AScrapCompactor()
{

	bReplicates = true;

	Model = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Model"));
	ScrapText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScrapText"));
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("EngineLoopAudio"));

	RootComponent = Model;
	ScrapText->SetupAttachment(RootComponent);
	AudioComponent->SetupAttachment(RootComponent);
}

void AScrapCompactor::BeginPlay()
{
	Super::BeginPlay();

	UpdateText();

	GetWorldTimerManager().SetTimer(ProductionTimerHandle, this, &AScrapCompactor::Server_ScrapProductionTick, ProduceTickRate, true, ProduceTickRate);

	/*
	if(HasAuthority())
	{
		GetWorldTimerManager().SetTimer(ProductionTimerHandle, this, &AScrapCompactor::Server_ScrapProductionTick, ProduceTickRate, true, ProduceTickRate);
	}
	*/	
}

void AScrapCompactor::Server_ScrapProductionTick_Implementation()
{
	CurrentScrap += ProduceAmount;
	CurrentScrap = FMath::Clamp(CurrentScrap, 0, MaxScrap);

	if(!IsRunningDedicatedServer())
	{
		UGameplayStatics::PlaySoundAtLocation(this, ProduceSound, GetActorLocation(), GetActorRotation(), 1.f, 1.f, 0.f);
	}

	OnRep_CurrentScrap();

	OnProductionTicked.Broadcast(CurrentScrap, MaxScrap);
}

void AScrapCompactor::UpdateText()
{
	ScrapText->SetText(FText::FromString(GetScrapString()));
}

void AScrapCompactor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AScrapCompactor, CurrentScrap);
	DOREPLIFETIME(AScrapCompactor, MaxScrap);
}

void AScrapCompactor::Interact_Implementation(ANightmarePlayerController* CallingController)
{
	if(CurrentScrap <= 0)
	{
		return;
	}

	ANightmarePlayer* Player = Cast<ANightmarePlayer>(CallingController->GetPawn());

	if(!Player)
	{
		return;
	}

	ANightmarePlayerState* PlayerState = Cast<ANightmarePlayerState>(Player->GetPlayerState());

	if(!PlayerState)
	{
		return;
	}

	PlayerState->AddScrap(CurrentScrap);

	CurrentScrap = 0;
	OnRep_CurrentScrap();

	if(!IsRunningDedicatedServer())
	{
		// netmulticast this!
		UGameplayStatics::PlaySoundAtLocation(this, CollectSound, GetActorLocation(), GetActorRotation(), 1.f, 1.f, 0.f);
	}
}

void AScrapCompactor::OnRep_CurrentScrap()
{
	UpdateText();

}

void AScrapCompactor::OnRep_MaxScrap()
{
	UpdateText();
}