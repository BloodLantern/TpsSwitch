// Fill out your copyright notice in the Description page of Project Settings.


#include "JojoPlayerController.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>

void AJojoPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 15.f, FColor::Emerald, FString::Printf(TEXT("Player controller id %d OnPossess"), PlayerId));
	if (APlayerJotaro* jotaro = Cast<APlayerJotaro>(aPawn))
	{
		Jotaro = jotaro;
		StarPlatinum = jotaro->StarPlatinum;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 15.f, FColor::Emerald, FString::Printf(TEXT("Player controller id %d OnPossess with Jotaro %p and StarPlatinum %p"), PlayerId, Jotaro, StarPlatinum));
	}
	else if (APlayerStarPlatinum* starPlatinum = Cast<APlayerStarPlatinum>(aPawn))
	{
		StarPlatinum = starPlatinum;
		Jotaro = starPlatinum->Jotaro;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 15.f, FColor::Emerald, FString::Printf(TEXT("Player controller id %d OnPossess with StarPlatinum %p and Jotaro %p"), PlayerId, StarPlatinum, Jotaro));
	}
}

void AJojoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 15.f, FColor::Emerald, FString::Printf(TEXT("Player controller id %d setup input"), PlayerId));
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
	if (!Jotaro)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("PlayerController player id: %d, no Jotaro"), PlayerId));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("Jotaro player id: %d, player: %d"), Jotaro->PlayerData.PlayerId, PlayerId));
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->InputCamera(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputMovement(const FInputActionValue& Value)
{
	if (!Jotaro)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("PlayerController player id: %d, no Jotaro"), PlayerId));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("Jotaro player id: %d, player: %d"), Jotaro->PlayerData.PlayerId, PlayerId));
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->InputMovement(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputJumpBegin()
{
	if (!Jotaro)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("PlayerController player id: %d, no Jotaro"), PlayerId));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("Jotaro player id: %d, player: %d"), Jotaro->PlayerData.PlayerId, PlayerId));
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldJump = true;
}

void AJojoPlayerController::InputJumpEnd()
{
	if (!Jotaro)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("PlayerController player id: %d, no Jotaro"), PlayerId));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("Jotaro player id: %d, player: %d"), Jotaro->PlayerData.PlayerId, PlayerId));
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldJump = false;
}

void AJojoPlayerController::InputSlideBegin()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("Jotaro player id: %d, player: %d"), Jotaro->PlayerData.PlayerId, PlayerId));
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldSlide = true;
}

void AJojoPlayerController::InputSlideEnd()
{
	if (!Jotaro)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("PlayerController player id: %d, no Jotaro"), PlayerId));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("Jotaro player id: %d, player: %d"), Jotaro->PlayerData.PlayerId, PlayerId));
	if (Jotaro->PlayerData.PlayerId == PlayerId)
		Jotaro->ShouldSlide = false;
}

void AJojoPlayerController::InputAim()
{
	if (!StarPlatinum)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("PlayerController player id: %d, no StarPlatinum"), PlayerId));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("StarPlatinum player id: %d, player: %d"), StarPlatinum->PlayerData.PlayerId, PlayerId));
	if (StarPlatinum->PlayerData.PlayerId == PlayerId)
		StarPlatinum->Aim();
}

void AJojoPlayerController::InputSwapPlayers()
{
	if (!StarPlatinum)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("PlayerController player id: %d, no StarPlatinum"), PlayerId));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.1f, FColor::Emerald, FString::Printf(TEXT("StarPlatinum player id: %d, player: %d"), StarPlatinum->PlayerData.PlayerId, PlayerId));
	if (StarPlatinum->PlayerData.PlayerId == PlayerId)
		StarPlatinum->SwapPlayers();
}
