#include "Workbench.h"
#include "UObject/Object.h"

AWorkbench::AWorkbench()
{
	bReplicates = true;
	Model = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Model"));
	RootComponent = Model;	
}

void AWorkbench::Interact_Implementation(class ANightmarePlayerController* CallingController)
{

}