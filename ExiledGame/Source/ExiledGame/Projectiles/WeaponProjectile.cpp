// @Maxpro 2017

#include "ExiledGame.h"
#include "../RnCCharacter.h"
#include "../AI/BaseEnemyCharacter.h"
#include "../Weapons/RangeWeapon.h"
#include "WeaponProjectile.h"


//-------------------------------------------------------------------------------------
//Called when the projectile stops
//-------------------------------------------------------------------------------------
void AWeaponProjectile::OnProjectileStop(const FHitResult& ImpactResult)
{
	Destroy();
}

// Sets default values
AWeaponProjectile::AWeaponProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initializing components
	BoxComp = CreateDefaultSubobject<UBoxComponent>(FName("BoxComp"));

	SetRootComponent(BoxComp);

	BulletComp = CreateDefaultSubobject<UParticleSystemComponent>(FName("BulletComp"));
	BulletComp->bAutoActivate = true;

	// TODO: Is this the correct transform rules?
	BulletComp->AttachToComponent(BoxComp, FAttachmentTransformRules::KeepRelativeTransform);

	ProjectileMoveComp = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComp"));

}

// Called when the game starts or when spawned
void AWeaponProjectile::BeginPlay()
{
	Super::BeginPlay();

	//Registering overlap function
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AWeaponProjectile::OnBoxOverlap);

	ProjectileMoveComp->OnProjectileStop.AddDynamic(this, &AWeaponProjectile::OnProjectileStop);

	//Get the total damage amount based on the owner
	ARangeWeapon* Owner = Cast<ARangeWeapon>(GetOwner());
	if (Owner)
	{
		DamageAmount = Owner->GetTotalDamageAmount();

		if (Owner->GetParticleSystemBasedOnLevel())
		{
			BulletComp->SetTemplate(Owner->GetParticleSystemBasedOnLevel());
		}
	}
}

//-------------------------------------------------------------------------------------
//Called when the projectile overlaps with another actor
//-------------------------------------------------------------------------------------
void AWeaponProjectile::OnBoxOverlap(UPrimitiveComponent* OverlapedComp, AActor* OverlapedActor, UPrimitiveComponent* MyComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	FDamageEvent DmgEvent;

	if (!OverlapedActor->IsA<ARnCCharacter>())
	{
		float RemainingHealth = OverlapedActor->TakeDamage(DamageAmount, DmgEvent, GetInstigatorController(), GetOwner());

		//If the overlaped actor is an enemy, calculate his remaining health and add xp if needed
		ABaseEnemyCharacter* BaseEnemy = Cast<ABaseEnemyCharacter>(OverlapedActor);
		AWeapon* Owner = Cast<AWeapon>(GetOwner());

		if (RemainingHealth <= 0 && Owner && BaseEnemy)
		{
			Owner->AddWeaponXP(BaseEnemy->GetXpReward());
		}
	}
}