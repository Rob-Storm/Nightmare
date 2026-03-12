using UnrealBuildTool;

public class NightmareTarget : TargetRules
{
	public NightmareTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		ExtraModuleNames.AddRange( new string[] { "NightmareCore" } );
	}
}