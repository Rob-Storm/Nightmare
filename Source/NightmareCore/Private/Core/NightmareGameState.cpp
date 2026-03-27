#include "Core/NightmareGameState.h"
#include "Net/UnrealNetwork.h"

ANightmareGameState::ANightmareGameState()
{
	bReplicateUsingRegisteredSubObjectList = true;
}

void ANightmareGameState::Server_SendChatMessage_Implementation(const FChatMessage& Message)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Message received"));

	ChatHistory.Add(Message);

	OnRep_ChatHistory();
}

void ANightmareGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANightmareGameState, ChatHistory);
}


void ANightmareGameState::OnRep_ChatHistory()
{
	OnChatHistoryChanged.Broadcast();
}