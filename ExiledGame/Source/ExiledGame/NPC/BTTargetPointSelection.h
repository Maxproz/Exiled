// @Maxpro 2017

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "BTTargetPointSelection.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API UBTTargetPointSelection : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
