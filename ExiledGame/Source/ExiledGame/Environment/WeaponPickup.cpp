// @Maxpro 2017

#include "ExiledGame.h"
#include "../Weapons/WeaponsComponent.h"
#include "../RnCCharacter.h"
#include "WeaponPickup.h"


//-------------------------------------------------------------------------------------
//Called when something overlaps with the actor
//-------------------------------------------------------------------------------------
void AWeaponPickup::OnActorOverlap(AActor* OverlapedActor, AActor* MyActor)
{
	ARnCCharacter* Char = Cast<ARnCCharacter>(OverlapedActor);

	//If the pickup has a valid weapon - unlock it for the character

	if (Char && WeaponBP)
	{
		UWeaponsComponent* WeaponsComp = Char->GetWeaponsComponent();
		if (WeaponsComp)
		{
			WeaponsComp->UnlockWeapon(WeaponBP->GetDefaultObject<AWeapon>()->GetWeaponType());
			Destroy();
		}
	}
}

// Sets default values
AWeaponPickup::AWeaponPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(FName("BoxComp"));

	SetRootComponent(BoxComp);

	WeaponSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("WeaponSkeletalMesh"));

	WeaponSkeletalMesh->AttachTo(GetRootComponent());

	RotatingMovementComp = CreateDefaultSubobject<URotatingMovementComponent>(FName("RotatingMovementComp"));

}

// Called when the game starts or when spawned
void AWeaponPickup::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AWeaponPickup::OnActorOverlap);

}


//-------------------------------------------------------------------------------------
//Updates the skeletal mesh of the weapon pickup if a valid blueprint is assigned
//-------------------------------------------------------------------------------------
void AWeaponPickup::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (WeaponBP)
	{
		WeaponSkeletalMesh->SetSkeletalMesh((WeaponBP->GetDefaultObject<AWeapon>())->GetWeaponSkeletalMesh()->SkeletalMesh);
	}
}