// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IncreaseDamage.generated.h"

class ATriggerVolume;
class AMain_Character;



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUN_API UIncreaseDamage : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UIncreaseDamage();

protected:


public:
	// Called every frame


	bool IncreaseDamagePlatePressured();

	bool getPressed();




private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* Damage_Increase_Plate;


	AMain_Character* PlayerRef;
	UPROPERTY(VisibleAnywhere)
		bool pressed = false;

	void IsPressured();

	void IncreaseDamage();

};


