// BallLifeDisappear.cpp

#include "BallLifeDisappear.h"
#include "IncreaseHealth.h"

UBallLifeDisappear::UBallLifeDisappear()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.
    PrimaryComponentTick.bCanEverTick = true;

    // Set default displacement amount
    DisplacementAmount = FVector(1000.0f, 1000.0f, 10000.0f);
}

void UBallLifeDisappear::BeginPlay()
{
    Super::BeginPlay();

    // Get the HealthPlateWatcher reference
    HealthPlateWatcher = GetOwner()->FindComponentByClass<UIncreaseHealth>();

    // Attach the MoveComponents function to the OnPressurePlatePressed event
    if (HealthPlateWatcher)
    {
        HealthPlateWatcher->OnPressurePlatePressed.AddDynamic(this, &UBallLifeDisappear::MoveComponents);
    }
}

void UBallLifeDisappear::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UBallLifeDisappear::MoveComponents()
{
    // Implement logic to move the components when the player passes through the pressure plate
    AActor* Owner = GetOwner();
    if (Owner)
    {
        Owner->AddActorWorldOffset(DisplacementAmount);
    }
}
