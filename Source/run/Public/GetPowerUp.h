// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GetPowerUp.generated.h"

class ATriggerVolume;
class AMain_Character;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUN_API UGetPowerUp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGetPowerUp();

public:	
	
	bool UnablePowerUp();

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PowerUpPlate;


	AMain_Character* PlayerRef;
		
};
