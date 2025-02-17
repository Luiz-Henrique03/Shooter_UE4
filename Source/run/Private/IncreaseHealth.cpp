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
	if (!PlayerRef) {
		UE_LOG(LogTemp, Error, TEXT("PlayerRef is nullptr"));
		return;
	}

	Ispressured();

	if (this->pressed) {
		auto HealthAux = PlayerRef->GetHealth();
		auto health = HealthAux + 100;
		PlayerRef->setHealth(health);
		UE_LOG(LogTemp, Warning, TEXT("Health increased to %f"), health);
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

	if (!Health_plate) {
		return;
	}

	if (Health_plate->IsOverlappingActor(Actor)) {
		this->pressed = true;
		Health_plate->Destroy();
		OnPressurePlatePressed.Broadcast();
	}
	else {
		this->pressed = false;
	}
}


