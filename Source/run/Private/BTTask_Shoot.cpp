// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "d:\games\run 4.26\Source\run\Main_Character.h"


UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr) {
		return EBTNodeResult::Failed;
	}
		

	AMain_Character* Character = Cast<AMain_Character>(OwnerComp.GetAIOwner()->GetPawn());

	if (Character == nullptr) {
		return EBTNodeResult::Failed;
	}
	

	Character->Fire();

	return EBTNodeResult::Succeeded;
}
