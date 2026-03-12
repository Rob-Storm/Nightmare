using UnrealBuildTool;

public class NightmareEditor : ModuleRules
{
	public NightmareEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnforceIWYU = true;	

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "NightmareCore" });
		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}