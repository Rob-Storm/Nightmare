#include "Inventory/ItemActor.h"
#include "UObject/Object.h"
#include "Net/UnrealNetwork.h"

#include "GameFramework/Character.h"
#include "NightmarePlayer.h"

AItemActor::AItemActor()
{
	bReplicates = true;
	
	Model = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Model"));

	RootComponent = Model;
}

void AItemActor::SetItemData(UItemData* NewItemData)
{
	ItemData = NewItemData;
	Model->SetStaticMesh(ItemData->WorldModel);

	OnRep_ItemData();
}

void AItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AItemActor, ItemData);
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

	if(Player)
	{
		Player->InventoryComponent->Server_AddItem(ItemData);
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

void AItemActor::OnRep_ItemData()
{
	Model->SetStaticMesh(ItemData->WorldModel);
}