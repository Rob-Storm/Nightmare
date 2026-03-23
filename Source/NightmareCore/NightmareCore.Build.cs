using UnrealBuildTool;

public class NightmareCore : ModuleRules
{
	public NightmareCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;	

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UMG",
		"OnlineSubsystem", "OnlineSubsystemUtils", "OnlineSubsystemSteam", "OnlineSubsystemNull", "Voice" });
		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}