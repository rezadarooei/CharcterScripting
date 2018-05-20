// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::StartSpring);
	PlayerInputComponent->BindAction("Sprint",  IE_Released, this, &AMyCharacter::EndSpring);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AMyCharacter::Reload);

}

void AMyCharacter::StartSpring()
{
	GLog->Log("StartSprint");
}

void AMyCharacter::EndSpring()
{
	GLog->Log("EndSprint");
}

void AMyCharacter::Reload()
{
	if (ReloadMontage) {
		PlayAnimMontage(ReloadMontage);
	}
}
