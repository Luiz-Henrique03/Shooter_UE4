// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "Enemys_AIController.h"

void AKillEmAllGameModeBase::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

	if (PlayerController != nullptr) {
		EndGame(false);
	}

	for (AEnemys_AIController* Controller : TActorRange<AEnemys_AIController>(GetWorld()))
	{
		if (!Controller->IsDead()) {
			return;
		}
	}
	EndGame(true);
}

void AKillEmAllGameModeBase::EndGame(bool bIsPlayerOne)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerOne;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	
	}
}
