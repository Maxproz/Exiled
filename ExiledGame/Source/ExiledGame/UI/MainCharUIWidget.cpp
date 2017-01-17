// @Maxpro 2017

#include "ExiledGame.h"
#include "../RnCCharacter.h"
#include "MainCharUIWidget.h"



//-------------------------------------------------------------------------------------
//Updates the health UI
//-------------------------------------------------------------------------------------
void UMainCharUIWidget::UpdateHealthValue()
{
	ARnCCharacter* MainChar = Cast<ARnCCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (MainChar)
	{
		//Convert the health to a percentage in order for the binding to work
		HealthValue = MainChar->GetHealthValue() / 100;
	}
}

//-------------------------------------------------------------------------------------
//Updates all the available bindings
//-------------------------------------------------------------------------------------
void UMainCharUIWidget::UpdateBindings()
{
	ARnCCharacter* MainChar = Cast<ARnCCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (MainChar)
	{
		HealthValue = MainChar->GetHealthValue() / 100;

		AmmoLeft = MainChar->GetAmmoLeft();
	}
}
