// BallLifeDisappear.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BallLifeDisappear.generated.h"

class UIncreaseHealth;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUN_API UBallLifeDisappear : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UBallLifeDisappear();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    UPROPERTY(EditAnywhere)
        FVector DisplacementAmount; // Amount to displace the components when the player passes through the pressure plate

    UIncreaseHealth* HealthPlateWatcher;

    UFUNCTION()
        void MoveComponents();
};
