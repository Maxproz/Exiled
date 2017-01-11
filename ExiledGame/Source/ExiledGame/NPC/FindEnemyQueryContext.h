// @Maxpro 2017

#pragma once

#include "EnvironmentQuery/EnvQueryContext.h"
#include "FindEnemyQueryContext.generated.h"

/**
 * 
 */
UCLASS()
class EXILEDGAME_API UFindEnemyQueryContext : public UEnvQueryContext
{
	GENERATED_BODY()
	

	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;

	
};
