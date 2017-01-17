// @Maxpro 2017

#include "ExiledGame.h"
#include "../RnCCharacter.h"
#include "RangeWeapon.h"

ARangeWeapon::ARangeWeapon()
{
	//Initialize Components

	AudioComp = CreateDefaultSubobject<UAudioComponent>(FName("AudioComp"));
	// Is this the correct transform rule here?
	AudioComp->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	AudioComp->bAutoActivate = false;


	//Initialize properties
	bIsMelee = false;
	LastTimeWeaponWasFired = 0.f;
	ProjectileSpeedMultiplier = 1.f;
	ProjectileSpawnLocationMultiplier = 50.f;

}

void ARangeWeapon::Fire()
{
	//Check if the weapon allow the character to fire
	if ((GetWorld()->GetTimeSeconds() - LastTimeWeaponWasFired >= FireRate) && CurrentAmmo>0)
	{
		//Play the fire audio
		AudioComp->Play();

		CurrentAmmo--;

		//Calculate the projectile travel path for raycast
		FVector SocketLocation = WeaponSM->GetSocketLocation(MuzzleSocket);
		FVector BulletEndTarget = SocketLocation + (GetActorForwardVector()*BulletMaxTravelDistance);

		//Apply a relatively smooth fix in Z axis because I don't have an animator and
		//I must make the most out of my animations (the attached weapon is too high because of the animation)
		BulletEndTarget.Z -= 50;

		//Debug line - for debug purposes
		//DrawDebugLine(GetWorld(), SocketLocation, BulletEndTarget, FColor::Blue, false, 2.f);


		if (WeaponProjectile)
		{
			FActorSpawnParameters SpawnParams;

			SpawnParams.Owner = this;

			//Calculate the new velocity for our projectile and normalize it
			FVector ProjectileVelocity = BulletEndTarget - SocketLocation;
			ProjectileVelocity.Normalize();


			FTransform ProjectileSpawnTransform = WeaponSM->GetSocketTransform(MuzzleSocket);
			ProjectileSpawnTransform.SetLocation(ProjectileSpawnTransform.GetLocation() + GetActorForwardVector() * ProjectileSpawnLocationMultiplier);

			//Access the player to determine if the projectiles should bounce
			ARnCCharacter* MainChar = Cast<ARnCCharacter>(GetOwner());
			bool ProjectilesBounceEffect = false;
			if (MainChar)
			{
				ProjectilesBounceEffect = MainChar->GetProjectileBounceEffect();
			}

			//Spawn the projectile
			AWeaponProjectile* Projectile = Cast<AWeaponProjectile>(GetWorld()->SpawnActor<AWeaponProjectile>(WeaponProjectile, ProjectileSpawnTransform, SpawnParams));

			if (Projectile)
			{
				if (ProjectilesBounceEffect)
				{
					Projectile->ProjectileMoveComp->bShouldBounce = true;
				}

				//Update the new velocity based on values we entered through the editor
				Projectile->ProjectileMoveComp->Velocity = ProjectileVelocity * Projectile->ProjectileMoveComp->InitialSpeed * ProjectileSpeedMultiplier;
				Projectile->ProjectileMoveComp->UpdateComponentVelocity();


			}
			LastTimeWeaponWasFired = GetWorld()->GetTimeSeconds();
		}
	}
}


