#include "NightmarePlayer.h"
#include "UObject/Object.h"

#include "Inventory/Item.h"
#include "Core/NightmarePlayerState.h"

ANightmarePlayer::ANightmarePlayer()
{
	bReplicates = true;
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
}


bool ANightmarePlayer::CanBuyRecipe(const FWorkbenchRecipe& Recipe) const
{
	ANightmarePlayerState* PS = Cast<ANightmarePlayerState>(GetPlayerState());

	if(!PS)
	{
		return false;
	}

	if(Recipe.OneAllowed)
	{
		UItem* OutItem;
		return !InventoryComponent->HasItem(Recipe.ItemData, OutItem) && PS->CurrentScrap >= Recipe.ScrapCost;
	}
	else
	{
		return PS->CurrentScrap >= Recipe.ScrapCost;
	}
		
}