// @Maxpro 2017

#pragma once

#include "Weapons/Weapon.h"
#include "Knife.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API AKnife : public AWeapon
{
	GENERATED_BODY()
	
public:

	AKnife();

	/*Returns hit actors*/
	virtual bool GetHitActors(TArray<FHitResult> &WeaponHitActors) override;
	
	
};
