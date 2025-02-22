// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "runGameModeBase.h"
#include "KillEmAllGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class RUN_API AKillEmAllGameModeBase : public ArunGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* PawnKilled) override;
	UFUNCTION(BlueprintPure)
	int GetEnemys();
private:
	void EndGame(bool bIsPlayerOne);
protected:
	UPROPERTY(BlueprintReadOnly)
		int EnemysCount = 17;

};
