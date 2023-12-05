// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mechanism.h"
#include "../../Public/Player/PlayerJotaro.h"
#include "Wall.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API AWall : public AMechanism
{
	GENERATED_BODY()
public:
	void BeginPlay();

	UFUNCTION(BlueprintCallable)
	void BeginHit(APlayerJotaro* player);


private:
	UStaticMeshComponent* m_Mesh;
};
