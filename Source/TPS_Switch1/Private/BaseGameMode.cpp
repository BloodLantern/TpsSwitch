// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"

UMaterialInterface* ABaseGameMode::GetPlayerColor(int PlayerId) const
{
	return PlayerColors[PlayerId];
}

UMaterialInterface* ABaseGameMode::GetRandomPlayerColor() const
{
	return GetPlayerColor(FMath::RandHelper(PlayerColors.Num()));
}
