// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NarutoNext : ModuleRules
{
	public NarutoNext(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// Core Dependencies
		PublicDependencyModuleNames.AddRange(
			new string[] { 
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore"
			}
		);

		// AI dependencies
		PrivateDependencyModuleNames.AddRange(
			new string[] { "AIModule" }
		);

		// Gameplay Ability System dependencies
		PublicDependencyModuleNames.AddRange(
			new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks", }
		);

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
