// @Maxpro 2017

#pragma once

#include "Blueprint/UserWidget.h"
#include "ThePauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API UThePauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
public:

	/*Plays the intro animation and adds the Widget to viewport*/
	UFUNCTION(BlueprintImplementableEvent, Category = "PauseMenuWidget")
	void Show();

	/*Plays the outro animation and removes the Widget from the viewport*/
	UFUNCTION(BlueprintImplementableEvent, Category = "PauseMenuWidget")
	void Hide();

};
	

