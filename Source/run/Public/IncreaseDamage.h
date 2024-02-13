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
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool IncreaseDamagePlatePressured();

	bool getPressed();




private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* Damage_Increase_Plate;


	AMain_Character* PlayerRef;
	UPROPERTY(VisibleAnywhere)
		bool pressed = false;

	void IsPressured();

};
