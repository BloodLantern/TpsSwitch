// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerJotaro.h"
#include "Player/PlayerStarPlatinum.h"

APlayerJotaro::APlayerJotaro()
{
}

void APlayerJotaro::BeginPlay()
{
	PlayerData.PlayerId = 0;

	Super::BeginPlay();
}
