#include "Inventory/ItemActor.h"
#include "UObject/Object.h"

#include "GameFramework/Character.h"
#include "NightmarePlayer.h"

AItemActor::AItemActor()
{
	Model = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Model"));

	RootComponent = Model;
}

void AItemActor::Interact_Implementation(ACharacter* CallingCharacter)
{
	ANightmarePlayer* Player = Cast<ANightmarePlayer>(CallingCharacter);

	if(!ItemData)
	{
		return;
	}

	if(!Player)
	{
		return;
	}

	FIntPoint InitialItemLocation;

	if(Player->InventoryComponent->CanItemFit(ItemData, InitialItemLocation))
	{
		Player->InventoryComponent->AddItem(ItemData, InitialItemLocation);
		Destroy();
	}

}

#if WITH_EDITOR

void AItemActor::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != nullptr)
		? PropertyChangedEvent.Property->GetFName()
		: NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AItemActor, ItemData))
	{
		if (ItemData && Model)
		{
			Model->SetStaticMesh(ItemData->WorldModel);
		}
	}
}

#endif