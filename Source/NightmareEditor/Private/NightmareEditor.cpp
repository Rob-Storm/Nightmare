#include "NightmareEditor.h"
#include "Modules/ModuleManager.h"

#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNightmareEditor, Log, All);
DEFINE_LOG_CATEGORY(LogNightmareEditor);

void FNightmareEditor::StartupModule()
{
	UE_LOG(LogNightmareEditor, Log, TEXT("NightmareEditor module starting up"));
}

void FNightmareEditor::ShutdownModule()
{
	UE_LOG(LogNightmareEditor, Log, TEXT("NightmareEditor module shutting down"));
}

IMPLEMENT_GAME_MODULE(FNightmareEditor, NightmareEditor);