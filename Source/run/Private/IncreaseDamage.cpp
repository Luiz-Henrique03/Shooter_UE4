// Fill out your copyright notice in the Description page of Project Settings.


#include "IncreaseDamage.h"
#include "d:\games\run 4.26\Source\run\Main_Character.h"
#include "Engine/TriggerVolume.h"

// Sets default values for this component's properties
UIncreaseDamage::UIncreaseDamage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIncreaseDamage::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UIncreaseDamage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UIncreaseDamage::IncreaseDamagePlatePressured()
{
	auto Actor = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (Damage_Increase_Plate->IsOverlappingActor(Actor)) {
		return true;

	}
	else {
		return  false;
	}

	return false;
}

bool UIncreaseDamage::getPressed()
{
	return this->pressed;
}





