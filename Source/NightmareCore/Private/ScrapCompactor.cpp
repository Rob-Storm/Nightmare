#include "ScrapCompactor.h"
#include "UObject/Object.h"
#include "Net/UnrealNetwork.h"

#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

AScrapCompactor::AScrapCompactor()
{
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

	if(HasAuthority())
	{
		GetWorldTimerManager().SetTimer(ProductionTimerHandle, this, &AScrapCompactor::ScrapProductionTick, ProduceTickRate, true, 0.f);
	}	
}

void AScrapCompactor::ScrapProductionTick_Implementation()
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

void AScrapCompactor::OnRep_CurrentScrap()
{
	UpdateText();

}

void AScrapCompactor::OnRep_MaxScrap()
{
	UpdateText();
}