// Fill out your copyright notice in the Description page of Project Settings.


#include "IncreaseHealth.h"
#include "d:\games\run 4.26\Source\run\Main_Character.h"
#include "Engine/TriggerVolume.h"

// Sets default values for this component's properties
UIncreaseHealth::UIncreaseHealth()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIncreaseHealth::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UIncreaseHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	
	IncreaseHelth();
	

}

void UIncreaseHealth::IncreaseHelth()
{
	PlayerRef = Cast<AMain_Character>(GetWorld()->GetFirstPlayerController()->GetPawn());
	Ispressured();
	if (this->pressed) {
		auto HealthAux = PlayerRef->GetHealth();
		auto health = HealthAux + 80;
		PlayerRef->setHealth(health);
	}
	
}

bool UIncreaseHealth::getPressed()
{
	return this->pressed;
}

void UIncreaseHealth::Ispressured()
{
	auto Actor = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!Actor) { return; }
	if (Health_plate->IsOverlappingActor(Actor)) {
		this->pressed = true;

		OnPressurePlatePressed.Broadcast();
	}
	else {
		this->pressed = false;
	}
	
}

