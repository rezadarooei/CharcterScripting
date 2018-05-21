// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraCompnent");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SPringArm");
	SpringArm->AttachTo(RootComponent);
	CameraComp->AttachTo(SpringArm,USpringArmComponent::SocketName);
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;
	CameraComp->bUsePawnControlRotation = false;
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
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);
	PlayerInputComponent->BindAction("Toggle", IE_Pressed, this, &AMyCharacter::Toggle);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUP", this, &AMyCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);


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

void AMyCharacter::MoveFoward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AMyCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void AMyCharacter::Toggle()
{
	bToggleIsOn = !bToggleIsOn;
	if (bToggleIsOn) {
		SpringArm->TargetArmLength = 0.f;
		GetMesh()->SetVisibility(false);
	}
	else
	{
		SpringArm->TargetArmLength = 300.f;
		GetMesh()->SetVisibility(true);

	}
}
