// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoo.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerVolume.h"


// Sets default values for this component's properties
UOpenDoo::UOpenDoo()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UOpenDoo::BeginPlay()
{
	Super::BeginPlay();

	if (!PressurePlate) { return; }

	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpen)) {
		OpenDoor(DeltaTime);
	}
	
	
}

void UOpenDoo::OpenDoor(float DeltaTime)
{
	CurrentLocation = GetOwner()->GetActorLocation();
	auto InitialLocation = GetOwner()->GetActorLocation().Y;
	CurrentLocation.Y = FMath::Lerp(InitialLocation, TargetYaw, DeltaTime * 0.9f);
	GetOwner()->SetActorLocation(CurrentLocation);
}



