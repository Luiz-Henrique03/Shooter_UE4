// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemys_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Main_Character.h"

void AEnemys_AIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	if (AIBehavior != nullptr) {
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}


}

void AEnemys_AIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (LineOfSightTo(PlayerPawn)) {
		GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	}
	else {
		GetBlackboardComponent()->ClearValue("PlayerLocation");
	}
	
}

bool AEnemys_AIController::IsDead() const
{
	AMain_Character* ControlledCharacter = Cast<AMain_Character>(GetPawn());

	if (ControlledCharacter != nullptr) {
		return ControlledCharacter->IsDead();

	}

	return true;
	
}
