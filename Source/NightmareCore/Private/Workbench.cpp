#include "Workbench.h"
#include "UObject/Object.h"

AWorkbench::AWorkbench()
{
	Model = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Model"));

	RootComponent = Model;
}