// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ThirstToLive : ModuleRules {
  public ThirstToLive(ReadOnlyTargetRules Target) : base(Target) {

    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

    PublicDependencyModuleNames.AddRange(
        new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });

    PrivateDependencyModuleNames.AddRange(
        new string[] { "Slate", "SlateCore" });

    PublicIncludePaths.AddRange(new string[] {

      "ThirstToLive/Public/Inventory",
      "ThirstToLive/Public/Inventory/InventoryItems",
      "ThirstToLive/Public/Character", "ThirstToLive/Public/Inventory/UI",
      "ThirstToLive/Public/Components"

    });
  }
}
