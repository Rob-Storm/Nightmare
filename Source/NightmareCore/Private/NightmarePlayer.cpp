#include "NightmarePlayer.h"
#include "UObject/Object.h"

ANightmarePlayer::ANightmarePlayer()
{
	bReplicates = true;
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
}