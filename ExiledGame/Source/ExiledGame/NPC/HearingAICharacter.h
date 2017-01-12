// @Maxpro 2017

#pragma once

#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "HearingAICharacter.generated.h"

UCLASS()
class EXILEDGAME_API AHearingAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHearingAICharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/*A Pawn Sensing Component, responsible for sensing other Pawns*/
	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensingComp;

	/*Hearing function - will be executed when we hear a Pawn*/
	UFUNCTION()
	void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);

	/*A Behavior Tree reference*/
	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* BehaviorTree;
	
};
