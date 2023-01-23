// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Enemys_AIController.generated.h"

/**
 * 
 */
UCLASS()
class RUN_API AEnemys_AIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;
private:
	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;
		//float AcceptanceRadius = 200;
};
