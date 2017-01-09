// @Maxpro 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "PlayerDataReader.generated.h"

UCLASS()
class EXILEDGAME_API APlayerDataReader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerDataReader();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
	UDataTable* DataTable;
	
};
