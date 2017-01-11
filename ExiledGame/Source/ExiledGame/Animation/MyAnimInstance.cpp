// @Maxpro 2017

#include "ExiledGame.h"
#include "MyAnimInstance.h"

void UMyAnimInstance::UpdateAnimationProperties()
{
	//Get the pawn which is affected by our anim instance
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		//Update our falling property
		bIsFalling = Pawn->GetMovementComponent()->IsFalling();

		//Update our movement speed
		MovementSpeed = Pawn->GetVelocity().Size();
	}
}


