// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_BlackboardBaseValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_BlackboardBaseValue::UBTTask_BlackboardBaseValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_BlackboardBaseValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}
