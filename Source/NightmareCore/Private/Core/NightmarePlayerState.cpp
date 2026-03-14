#include "Core/NightmarePlayerState.h"

void ANightmarePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANightmarePlayerState, CurrentScrap);
}

void ANightmarePlayerState::OnRep_CurrentScrap()
{
	OnScrapChanged.Broadcast(CurrentScrap);
}