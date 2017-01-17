// @Maxpro 2017

#include "ExiledGame.h"
#include "../RnCCharacter.h"
#include "MainCharacterAnimInstance.h"



float UMainCharacterAnimInstance::GetMainCharacterSpeed()
{
	APawn* Pawn = TryGetPawnOwner();
	if (Pawn)
	{
		CharacterSpeed = Pawn->GetVelocity().Size();
		return CharacterSpeed;
	}
	return 0;
}

void UMainCharacterAnimInstance::UpdateMovementSpeed()
{
	//Get the pawn and if it's valid, update the movement speed to update
	//the movement animation
	APawn* Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		CharacterSpeed = Pawn->GetVelocity().Size();
	}
}

bool UMainCharacterAnimInstance::MontageIsPlaying(UAnimMontage* MeleeAtkMontage)
{
	if (Montage_IsPlaying(MeleeAtkMontage))
	{
		return true;
	}
	return false;
}

void UMainCharacterAnimInstance::UpdateFallingStatus()
{
	APawn* Pawn = TryGetPawnOwner();
	if (Pawn)
	{
		bIsFalling = Pawn->GetMovementComponent()->IsFalling();
	}
}

void UMainCharacterAnimInstance::Attack()
{
	if (MeleeAttackAnimMontage)
	{
		Montage_Play(MeleeAttackAnimMontage);
	}
}

void UMainCharacterAnimInstance::PlayGetHitAnimation()
{
	APawn* Pawn = TryGetPawnOwner();
	if (Pawn)
	{
		if (bIsMelee && MeleeGetHitAnimMontage && !Montage_IsPlaying(MeleeGetHitAnimMontage) &&
			MeleeAttackAnimMontage && !Montage_IsPlaying(MeleeAttackAnimMontage)) Montage_Play(MeleeGetHitAnimMontage);

		else if (!bIsMelee && RangeGetHitAnimMontage && !Montage_IsPlaying(RangeGetHitAnimMontage)) Montage_Play(RangeGetHitAnimMontage);
		//TODO: range weapon equiped get hit anim montage 
	}
}

void UMainCharacterAnimInstance::ContinueMeleeCombo()
{
	FName CurrentSection = Montage_GetCurrentSection(MeleeAttackAnimMontage);

	//Determine the current status of the montage and play the corresponding
	//combo move if the player makes a successful combat move

	if (CurrentSection.IsEqual(FName("Attack1")) && bAcceptsSecondAttackInput)
	{
		Montage_JumpToSection(FName("Attack2"), MeleeAttackAnimMontage);
	}
	else if (CurrentSection.IsEqual(FName("Attack2")) && bAcceptsThirdAttackInput)
	{
		Montage_JumpToSection(FName("Attack3"), MeleeAttackAnimMontage);
	}
}

void UMainCharacterAnimInstance::PlayDeathAnimation()
{
	bIsDead = true;
}

void UMainCharacterAnimInstance::IsFiringWhileIdle()
{
	ARnCCharacter* Character = Cast<ARnCCharacter>(TryGetPawnOwner());
	if (Character && CharacterSpeed <= GunIdleThreshold && Character->IsFiringAGun() && IdleShootingAnimMontage)
	{
		if (!Montage_IsPlaying(IdleShootingAnimMontage)) Montage_Play(IdleShootingAnimMontage);

	}
}

void UMainCharacterAnimInstance::UpdateMeleeStatus()
{
	ARnCCharacter* Character = Cast<ARnCCharacter>(TryGetPawnOwner());
	if (Character)
	{
		bIsMelee = Character->IsMeleeWeaponEquipped();
	}
}


