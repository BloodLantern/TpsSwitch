// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBase.h"
#include "PlayerJotaro.generated.h"

class APlayerStarPlatinum;

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API APlayerJotaro : public APlayerBase
{
	GENERATED_BODY()
	
public:
	APlayerJotaro();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
	APlayerStarPlatinum* StarPlatinum;

protected:
	virtual void BeginPlay() override;
};
