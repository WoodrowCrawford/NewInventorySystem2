// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "InventorySystemGameMode.h"
#include "InventorySystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInventorySystemGameMode::AInventorySystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
