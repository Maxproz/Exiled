// @Maxpro 2017

#pragma once

#include "GameFramework/PlayerController.h"
#include "../UI/ThePauseMenuWidget.h"
#include "../UI/MainCharUIWidget.h"
#include "../UI/DeathMenuWidget.h"
#include "RnCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API ARnCPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	/*PauseMenu UI Reference*/
	UThePauseMenuWidget* PauseMenuWidget;

	/*Character's HUD reference*/
	UMainCharUIWidget* MainCharWidget;

	/*Death UI Reference*/
	UDeathMenuWidget* DeathMenuWidget;

protected:

	/*PauseMenu UI Blueprint Reference*/
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UThePauseMenuWidget> PauseMenuWidgetBP;

	/*Character's HUD BP Reference*/
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMainCharUIWidget> MainCharWidgetBP;

	/*DeathMenu UI Blueprint Reference*/
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDeathMenuWidget> DeathMenuWidgetBP;

public:

	virtual void Possess(APawn* InPawn) override;

	virtual void UnPossess() override;

	/*Pauses / un-pauses the game based on input*/
	UFUNCTION(BlueprintCallable, Category = "Pause")
	void HandlePauseState();

	void EnableBossUI();

	/*Updates the main character's UI*/
	void UpdateUI();

};
	
	

