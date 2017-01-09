// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ExiledGame.h"
#include "ExiledGameGameMode.h"
#include "ExiledGameHUD.h"
#include "ExiledGameCharacter.h"

AExiledGameGameMode::AExiledGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AExiledGameHUD::StaticClass();
}
