#include "NightmarePlayer.h"
#include "UObject/Object.h"

ANightmarePlayer::ANightmarePlayer()
{
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
}