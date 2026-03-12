#include "NightmareCore.h"
#include "Modules/ModuleManager.h"

#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNightmareCore, Log, All);
DEFINE_LOG_CATEGORY(LogNightmareCore);

void FNightmareCore::StartupModule()
{
	UE_LOG(LogNightmareCore, Log, TEXT("NightmareCore module starting up"));
}

void FNightmareCore::ShutdownModule()
{
	UE_LOG(LogNightmareCore, Log, TEXT("NightmareCore module shutting down"));
}

IMPLEMENT_GAME_MODULE(FNightmareCore, NightmareCore);