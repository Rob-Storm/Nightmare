#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FNightmareCore : public IModuleInterface
{
public:
	static inline FNightmareCore& Get()
	{
		return FModuleManager::LoadModuleChecked<FNightmareCore>("NightmareCore");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("NightmareCore");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};