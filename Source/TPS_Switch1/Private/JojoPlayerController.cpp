// Fill out your copyright notice in the Description page of Project Settings.


#include "JojoPlayerController.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>

AJojoPlayerController::AJojoPlayerController()
{
	PlayerId = LastPlayerId++;
}

void AJojoPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (APlayerJotaro* jotaro = Cast<APlayerJotaro>(aPawn))
		Jotaro = jotaro;
}

void AJojoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(CameraAction, ETriggerEvent::Triggered, this, &ThisClass::InputCamera);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::InputMovement);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::InputJumpBegin);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::InputJumpEnd);
	EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Triggered, this, &ThisClass::InputSlideBegin);
	EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Completed, this, &ThisClass::InputSlideEnd);
	EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &ThisClass::InputAim);
	EnhancedInputComponent->BindAction(SwapPlayersAction, ETriggerEvent::Triggered, this, &ThisClass::InputSwapPlayers);

	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!MappingContext.IsNull())
				InputSystem->AddMappingContext(MappingContext.LoadSynchronous(), 0);
		}
	}
}

void AJojoPlayerController::InputCamera(const FInputActionValue& Value)
{
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->InputCamera(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputMovement(const FInputActionValue& Value)
{
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->InputMovement(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputJumpBegin()
{
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldJump = true;
}

void AJojoPlayerController::InputJumpEnd()
{
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldJump = false;
}

void AJojoPlayerController::InputSlideBegin()
{
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldSlide = true;
}

void AJojoPlayerController::InputSlideEnd()
{
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldSlide = false;
}

void AJojoPlayerController::InputAim()
{
	if (StarPlatinum->PlayerData.PlayerId == PlayerId)
		StarPlatinum->Aim();
}

void AJojoPlayerController::InputSwapPlayers()
{
	if (StarPlatinum->PlayerData.PlayerId == PlayerId)
		StarPlatinum->SwapPlayers();
}
