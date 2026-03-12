#include "ScrapCompactor.h"
#include "UObject/Object.h"

AScrapCompactor::AScrapCompactor()
{
	Model = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Model"));
	ScrapText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScrapText"));

	RootComponent = Model;
	ScrapText->SetupAttachment(RootComponent);
}

void AScrapCompactor::ProductionTick_Implementation()
{
	CurrentScrap += ProduceAmount;
	CurrentScrap = FMath::Clamp(CurrentScrap, 0, MaxScrap);

	UpdateText();

	OnProductionTicked.Broadcast(CurrentScrap, MaxScrap);
}

void AScrapCompactor::SetScrapAmount_Implementation(int32 Amount)
{
	CurrentScrap = Amount;
	UpdateText();
}

void AScrapCompactor::UpdateText()
{
	ScrapText->SetText(FText::FromString(GetScrapString()));
}