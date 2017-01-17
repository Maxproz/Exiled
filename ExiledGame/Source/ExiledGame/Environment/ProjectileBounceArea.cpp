// @Maxpro 2017

#include "ExiledGame.h"
#include "ProjectileBounceArea.h"



// Sets default values
AProjectileBounceArea::AProjectileBounceArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AreaSM = CreateDefaultSubobject<UStaticMeshComponent>(FName("AreaSM"));

	SetRootComponent(AreaSM);
}

