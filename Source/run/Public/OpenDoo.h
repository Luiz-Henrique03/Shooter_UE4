// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoo.generated.h"

class ATriggerVolume;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUN_API UOpenDoo : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoo();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor(float DeltaTime);

	void CloseDoor(float DeltaTime);

private:
	UPROPERTY(EditAnywhere)
	float TargetYaw = -1815.f;

	UPROPERTY(EditAnywhere)
		float InitialYaw = -1465.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
		AActor* ActorThatOpen;
	
	FVector CurrentLocation;
	

		
};
