// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerJotaro.h"
#include "Player/PlayerStarPlatinum.h"
#include <JojoPlayerController.h>

APlayerJotaro::APlayerJotaro()
{
}

void APlayerJotaro::BeginPlay()
{
	PlayerData.PlayerId = 0;

	Super::BeginPlay();
}

void APlayerJotaro::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString::FromInt(PlayerInputComponent->IsA<AJojoPlayerController>()));
}
