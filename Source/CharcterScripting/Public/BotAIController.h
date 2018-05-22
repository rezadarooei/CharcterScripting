// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "BotAIController.generated.h"

class UBlackboardComponent;
class UPawnSensingComponent;
class UBehaviorTree;
class UBehaviorTreeComponent;
UCLASS()
class CHARCTERSCRIPTING_API ABotAIController : public AAIController
{
	GENERATED_BODY()
public:
	ABotAIController();
	virtual void Possess(APawn* InPawn) override;
protected:
	UPROPERTY(EditDefaultsOnly,Category="AI")
	UBlackboardComponent* BlacBoardComponent;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTreeComponent* bahaviorTreeComponent;

	UPROPERTY(EditDefaultsOnly, Category = "AI")

		UBehaviorTree* BahaviorTree;
	UPROPERTY(EditDefaultsOnly, Category = "AI")

	UPawnSensingComponent* PawnSensig;

	
	
	UFUNCTION()
		void OnSeenPawn(class APawn* SensedPawn);

};
