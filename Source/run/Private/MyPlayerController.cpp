// Fill out your copyright notice in the Description page of Project Settings.


#include "MYPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AMyPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr) {
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr) {
			LoseScreen->AddToViewport();
		}
	}
	HUD->RemoveFromViewport();
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartTime);
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr) {
		HUD->AddToViewport();
	}
}
