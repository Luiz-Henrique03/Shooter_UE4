// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "Enemys_AIController.h"

void AKillEmAllGameModeBase::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    // Verifique se o Pawn é um jogador
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
        return;
    }

    // Verifique se o Pawn é controlado por AEnemys_AIController
    AEnemys_AIController* AIController = Cast<AEnemys_AIController>(PawnKilled->GetController());
    if (AIController != nullptr)
    {
        if (AIController->IsDead())
        {
            EnemysCount--;
            UE_LOG(LogTemp, Warning, TEXT("Enemies remaining: %d"), EnemysCount);

            if (EnemysCount <= 0)
            {
                EndGame(true);
            }
        }
    }
}


int AKillEmAllGameModeBase::GetEnemys()
{
    return this->EnemysCount;
}

void AKillEmAllGameModeBase::EndGame(bool bIsPlayerOne)
{

	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerOne;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	
	}
}
