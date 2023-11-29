// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"

void ABaseGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
}

UMaterialInterface* ABaseGameMode::GetPlayerColor(int PlayerId) const
{
	return PlayerColors[PlayerId];
}

UMaterialInterface* ABaseGameMode::GetRandomPlayerColor() const
{
	return GetPlayerColor(FMath::RandHelper(PlayerColors.Num()));
}
