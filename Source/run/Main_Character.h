// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main_Character.generated.h"

class AGunActor;
class ATriggerVolume;
class UGetPowerUp;

UCLASS()
class RUN_API AMain_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain_Character();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
		bool GetPowerUp;


public:	

	UFUNCTION(BlueprintPure)
	bool IsDead() const;
	UPROPERTY(BlueprintReadWrite)
		bool IsUnablePowerUp;


	UFUNCTION(BlueprintPure)
	 float GetPercentHealth() const;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void Fire();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float AxisValue);
	void MoveBack (float AxisValue);
	void MoveRight(float AxisValue);
	void MoveLeft (float AxisValue);

	void LooksY(float AxisValue);
	void LooksX(float AxisValue);



	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGunActor> GunClass;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(EditAnywhere)
	float Health;


	AActor* Player;



	UPROPERTY()
	AGunActor* Gun;



};
