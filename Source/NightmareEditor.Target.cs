using UnrealBuildTool;

public class NightmareEditorTarget : TargetRules
{
	public NightmareEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		ExtraModuleNames.AddRange( new string[] { "NightmareCore" } );
	}
}