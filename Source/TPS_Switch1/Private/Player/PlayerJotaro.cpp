// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerJotaro.h"
#include "Player/PlayerStarPlatinum.h"
#include <JojoPlayerController.h>
#include "Kismet/KismetMathLibrary.h"

APlayerJotaro::APlayerJotaro()
{
}

void APlayerJotaro::InputMovement(float Value)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(GetControlRotation()), Value);
}

void APlayerJotaro::BeginPlay()
{
	PlayerData.PlayerId = 0;

	Super::BeginPlay();
}

void APlayerJotaro::Tick(float DeltaTime)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(GetControlRotation()), 1.f);
}
