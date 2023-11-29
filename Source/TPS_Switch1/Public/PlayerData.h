// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntityData.h"
#include "PlayerData.generated.h"

/**
 * 
 */
USTRUCT()
struct TPS_SWITCH1_API FPlayerData : public FEntityData
{
	GENERATED_BODY()

public:
	FPlayerData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EntityData)
	int PlayerId;
};
