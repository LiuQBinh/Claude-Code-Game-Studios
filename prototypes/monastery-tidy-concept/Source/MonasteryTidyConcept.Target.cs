// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

using UnrealBuildTool;
using System.Collections.Generic;

public class MonasteryTidyConceptTarget : TargetRules
{
	public MonasteryTidyConceptTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
		ExtraModuleNames.Add("MonasteryTidyConcept");
	}
}
