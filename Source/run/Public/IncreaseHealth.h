// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IncreaseHealth.generated.h"

class ATriggerVolume;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUN_API UIncreaseHealth : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIncreaseHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	bool Ispressured();
		
};
