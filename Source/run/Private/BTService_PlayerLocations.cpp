// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocations.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFrameWork/Pawn.h"

UBTService_PlayerLocations::UBTService_PlayerLocations()
{
	NodeName = TEXT("Update Player Movement");
}

void UBTService_PlayerLocations::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn == nullptr) {
		return;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());

}
