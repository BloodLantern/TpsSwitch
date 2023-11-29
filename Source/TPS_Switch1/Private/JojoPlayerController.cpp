// Fill out your copyright notice in the Description page of Project Settings.


#include "JojoPlayerController.h"

void AJojoPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (APlayerJotaro* jotaro = Cast<APlayerJotaro>(aPawn))
		Jotaro = jotaro;
}

void AJojoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Aim", IE_Pressed, this, &ThisClass::InputAimPressed);
	InputComponent->BindAction("Aim", IE_Released, this, &ThisClass::InputAimReleased);
}

void AJojoPlayerController::InputAimPressed()
{
	StarPlatinum->OnInputPressed();
}

void AJojoPlayerController::InputAimReleased()
{
	StarPlatinum->OnInputReleased();
}
