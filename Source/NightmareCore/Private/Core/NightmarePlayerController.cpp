#include "Core/NightmarePlayerController.h"

#include "Widgets/WorkbenchWidget.h"

// The player state is not valid at BeginPlay so we must use this function instead
void ANightmarePlayerController::BeginPlayingState()
{
	CreateScrapUI();
}