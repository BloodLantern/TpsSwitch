// Fill out your copyright notice in the Description page of Project Settings.


#include "JojoPlayerController.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <Kismet/GameplayStatics.h>

void AJojoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	m_GameMode = Cast<ABaseGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void AJojoPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (APlayerJotaro* jotaro = Cast<APlayerJotaro>(aPawn))
	{
		Jotaro = jotaro;
		StarPlatinum = jotaro->StarPlatinum;
	}
	else if (APlayerStarPlatinum* starPlatinum = Cast<APlayerStarPlatinum>(aPawn))
	{
		StarPlatinum = starPlatinum;
		Jotaro = starPlatinum->Jotaro;
	}
}

void AJojoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::InputMovement);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::InputJumpBegin);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::InputJumpEnd);
	EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Triggered, this, &ThisClass::InputSlideBegin);
	EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Completed, this, &ThisClass::InputSlideEnd);
	EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &ThisClass::InputAim);
	EnhancedInputComponent->BindAction(MoveCursorAction, ETriggerEvent::Triggered, this, &ThisClass::InputMoveCursor);
	EnhancedInputComponent->BindAction(SwapPlayersAction, ETriggerEvent::Triggered, this, &ThisClass::InputSwapPlayers);

	return;

	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!MappingContext.IsNull())
				InputSystem->AddMappingContext(MappingContext.LoadSynchronous(), 0);
		}
	}
}

bool AJojoPlayerController::CanUseInput(APlayerBase* PlayerCharacter)
{
	return PlayerCharacter->PlayerData.PlayerId == PlayerId && !m_GameMode->InMenus;
}

void AJojoPlayerController::InputMovement(const FInputActionValue& Value)
{
	if (CanUseInput(Jotaro))
		Jotaro->InputMovement(Value.Get<float>());
}

void AJojoPlayerController::InputJumpBegin()
{
	if (CanUseInput(Jotaro))
		Jotaro->ShouldJump = true;
}

void AJojoPlayerController::InputJumpEnd()
{
	if (CanUseInput(Jotaro))
		Jotaro->ShouldJump = false;
}

void AJojoPlayerController::InputSlideBegin()
{
	if (CanUseInput(Jotaro))
		Jotaro->ShouldSlide = true;
}

void AJojoPlayerController::InputSlideEnd()
{
	if (CanUseInput(Jotaro))
		Jotaro->ShouldSlide = false;
}

void AJojoPlayerController::InputAim()
{
	if (CanUseInput(StarPlatinum))
		StarPlatinum->Aim();
}

void AJojoPlayerController::InputMoveCursor(const FInputActionValue& Value)
{
	if (CanUseInput(StarPlatinum))
		StarPlatinum->MoveCursor(Value.Get<FVector2D>());
}

void AJojoPlayerController::InputSwapPlayers()
{
#if !UE_EDITOR
	if (CanUseInput(StarPlatinum))
#endif
		StarPlatinum->SwapPlayers();
}
