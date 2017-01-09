// @Maxpro 2017

#pragma once

#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "PlayerStats.generated.h"

/**
 * 
 */
/*UCLASS()
class EXILEDGAME_API UPlayerStats : public UObject
{
	GENERATED_BODY()
	
	
	
	
};*/

USTRUCT(BlueprintType)
struct FPlayerStats : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	/*The xp need for the next level*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 XpToLevel;

	/*The health that the player has in the current level*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;
};