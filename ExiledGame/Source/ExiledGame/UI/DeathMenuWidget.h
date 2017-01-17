// @Maxpro 2017

#pragma once

#include "Blueprint/UserWidget.h"
#include "DeathMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API UDeathMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	/*Plays the entry animation of the death menu widget*/
	UFUNCTION(BlueprintImplementableEvent, Category = "DeathWidget")
	void Show();

};
	

