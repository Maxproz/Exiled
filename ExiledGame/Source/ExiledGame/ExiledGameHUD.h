// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "ExiledGameHUD.generated.h"

UCLASS()
class AExiledGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AExiledGameHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

