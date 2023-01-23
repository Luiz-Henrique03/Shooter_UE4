// Fill out your copyright notice in the Description page of Project Settings.


#include "GetPowerUp.h"
#include "Engine/TriggerVolume.h"

// Sets default values for this component's properties
UGetPowerUp::UGetPowerUp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}

bool UGetPowerUp::UnablePowerUp()
{
	auto Actor = GetWorld()->GetFirstPlayerController();
	if (!Actor) { return false; }
	if (PowerUpPlate->IsOverlappingActor(Actor)) {
		return true;
	}
	else {
		return false;
	}
}

