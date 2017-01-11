// @Maxpro 2017

#pragma once

#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/*In case you want to handle animation montages using C++, inside this class
 you have the ability to call functions like Montage_Play / Montage_IsPlaying,
 Montage_Stop and provide a UAnimMontage* parameter.
*/

/**
 * 
 */
UCLASS()
class EXILEDGAME_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

protected:
	/*True means that we're currently in air - or falling*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsFalling;

	/*Holds the current speed of our character*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MovementSpeed;

	/*Updates the above properties*/
	UFUNCTION(BlueprintCallable, Category = "UpdateAnimationProperties")
	void UpdateAnimationProperties();
	
	
};
