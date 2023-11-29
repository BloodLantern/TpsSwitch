// Fill out your copyright notice in the Description page of Project Settings.


#include "JojoPlayerController.h"
#include <EnhancedInputComponent.h>

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

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		/*EnhancedInputComponent->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ThisClass::MoveCamera);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::MovePlayer);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &ThisClass::Attack);
		EnhancedInputComponent->BindAction(BlockAction, ETriggerEvent::Triggered, this, &ThisClass::BlockTriggered);
		EnhancedInputComponent->BindAction(LockAction, ETriggerEvent::Started, this, &ThisClass::Lock);*/
	}
}

void AJojoPlayerController::InputAimPressed()
{
	StarPlatinum->OnInputPressed();
}

void AJojoPlayerController::InputAimReleased()
{
	StarPlatinum->OnInputReleased();
}
