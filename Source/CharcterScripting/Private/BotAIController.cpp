// Fill out your copyright notice in the Description page of Project Settings.

#include "BotAIController.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/Perception/PawnSensingComponent.h"
#include "BotCharacter.h"

ABotAIController::ABotAIController()
{

	bahaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("BehavioTreeComponent");
	BlacBoardComponent= CreateDefaultSubobject<UBlackboardComponent>("BlackBoardComponent");
	PawnSensig = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");

}


void ABotAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);
	PawnSensig->OnSeePawn.AddDynamic(this, &ABotAIController::OnSeenPawn);
	if (BahaviorTree) {
		BlacBoardComponent->InitializeBlackboard(*BahaviorTree->BlackboardAsset);
		bahaviorTreeComponent->StartTree(*BahaviorTree);
		BlacBoardComponent->SetValueAsBool("ShouldWander",true);
	}
}

void ABotAIController::OnSeenPawn(class APawn* SensedPawn)
{
	if (BlacBoardComponent && SensedPawn) {
		BlacBoardComponent->SetValueAsBool("ShouldWander", false);

		BlacBoardComponent->SetValueAsObject("Enemy", SensedPawn);

	}
}

