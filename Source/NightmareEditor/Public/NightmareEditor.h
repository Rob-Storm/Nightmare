#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FNightmareEditor : public IModuleInterface
{
public:
	static inline FNightmareEditor& Get()
	{
		return FModuleManager::LoadModuleChecked<FNightmareEditor>("NightmareEditor");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("NightmareEditor");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};