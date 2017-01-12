// @Maxpro 2017

#include "ExiledGame.h"
#include "HearingAIController.h"
#include "HearingAICharacter.h"


// Called every frame
void AHearingAICharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AHearingAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Sets default values
AHearingAICharacter::AHearingAICharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initializing our Pawn Sensing comp and our behavior tree reference
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	BehaviorTree = CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTreeReference"));
}

// Called when the game starts or when spawned
void AHearingAICharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		//Registering the delegate which will fire when we hear something
		PawnSensingComp->OnHearNoise.AddDynamic(this, &AHearingAICharacter::OnHearNoise);
	}

}

void AHearingAICharacter::OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume)
{

	AHearingAIController* Con = Cast<AHearingAIController>(GetController());

	//We don't want to hear ourselves
	if (Con && PawnInstigator != this)
	{
		//Updates our target based on what we've heard.
		Con->SetSensedTarget(PawnInstigator);
	}
}