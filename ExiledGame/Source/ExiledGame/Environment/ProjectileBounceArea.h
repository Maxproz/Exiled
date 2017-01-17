// @Maxpro 2017

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectileBounceArea.generated.h"



UCLASS()
class EXILEDGAME_API AProjectileBounceArea : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AProjectileBounceArea();

	/*The static mesh of the wall*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* AreaSM;

};

	
	

