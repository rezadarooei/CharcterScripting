// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CharcterScriptingGameMode.h"
#include "CharcterScriptingCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACharcterScriptingGameMode::ACharcterScriptingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
