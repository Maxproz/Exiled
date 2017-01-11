// @Maxpro 2017

#pragma once

#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
	
	/*Behavior tree comp ref*/
	UBehaviorTreeComponent* BehaviorComp;
	

	/*----------Blackboard----------*/


	/*Blackboard comp ref*/
	UBlackboardComponent* BlackboardComp;

	/*Blackboard keys*/
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName LocationToGoKey;


	/*----------Blackboard----------*/

	/*I use the AActor class as the Template class so I can use the GetAllActorsOfClass function.
	However, in this collection I'm going to store all the Available ABotTargetPoint instances.*/
	TArray<AActor*> BotTargetPoints;

	/*Posses is executed when the character we want to control is spawned.
	Inside this function, we initialize the blackboard and start the behavior tree*/
	virtual void Possess(APawn* ThePawn) override;

public:

	/*----------Constructor----------*/
	AMyAIController();

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

	FORCEINLINE TArray<AActor*> GetAvailableTargetPoints() { return BotTargetPoints; }


};
