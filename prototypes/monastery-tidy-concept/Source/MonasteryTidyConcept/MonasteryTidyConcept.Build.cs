// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

using UnrealBuildTool;

public class MonasteryTidyConcept : ModuleRules
{
	public MonasteryTidyConcept(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
			"Slate",
			"SlateCore"
		});
	}
}
