// Fill out your copyright notice in the Description page of Project Settings.


#include "JojoPlayerController.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>

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
	Jotaro->InputCamera(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputMovement(const FInputActionValue& Value)
{
	Jotaro->InputMovement(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputJumpBegin()
{
	Jotaro->ShouldJump = true;
}

void AJojoPlayerController::InputJumpEnd()
{
	Jotaro->ShouldJump = false;
}

void AJojoPlayerController::InputSlideBegin()
{
	Jotaro->ShouldSlide = true;
}

void AJojoPlayerController::InputSlideEnd()
{
	Jotaro->ShouldSlide = false;
}

void AJojoPlayerController::InputAim()
{
	StarPlatinum->Aim();
}

void AJojoPlayerController::InputSwapPlayers()
{
	StarPlatinum->SwapPlayers();
}
