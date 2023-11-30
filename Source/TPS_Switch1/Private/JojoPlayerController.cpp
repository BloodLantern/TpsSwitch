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

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("SetupInputComponent"));
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("EnhancedInputSetup"));
		EnhancedInputComponent->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ThisClass::InputCamera);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::InputMovement);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::InputJump);
		EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Triggered, this, &ThisClass::InputSlide);
		EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &ThisClass::InputAim);
		EnhancedInputComponent->BindAction(SwapPlayersAction, ETriggerEvent::Triggered, this, &ThisClass::InputSwapPlayers);
	}
}

void AJojoPlayerController::InputCamera(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("InputCamera"));
	Jotaro->InputCamera(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputMovement(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("InputMovement"));
	Jotaro->InputMovement(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputJump()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("InputJump"));
}

void AJojoPlayerController::InputSlide()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("InputSlide"));
}

void AJojoPlayerController::InputAim()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("InputAim"));
	StarPlatinum->Aim();
}

void AJojoPlayerController::InputSwapPlayers()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("InputSwap"));
	StarPlatinum->SwapPlayers();
}
