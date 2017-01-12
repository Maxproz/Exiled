// @Maxpro 2017

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HearingAIController.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API AHearingAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	/*A Behavior tree component in order to be able to call specific functions like starting our BT*/
	UBehaviorTreeComponent* BehaviorTreeComp;

	/*A Blackboard component which will be used to initialize our Blackboard Values*/
	UBlackboardComponent* BlackboardComp;

	/*This property is used to find a certain key for our blackboard.
	We will create the blackboard later in this tutorial*/
	UPROPERTY(EditDefaultsOnly)
	FName TargetKey = "SensedPawn";

public:
	/*Default Constructor*/
	AHearingAIController();

	/*Called when the AI Controller possesses a Pawn*/
	virtual void Possess(APawn* InPawn) override;

	/*Sets the new sensed target value inside our Blackboard values*/
	void SetSensedTarget(APawn* NewTarget);
	
	
};
