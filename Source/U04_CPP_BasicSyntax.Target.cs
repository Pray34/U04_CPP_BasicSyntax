// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class U04_CPP_BasicSyntaxTarget : TargetRules
{
	public U04_CPP_BasicSyntaxTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "U04_CPP_BasicSyntax" } );
	}
}
