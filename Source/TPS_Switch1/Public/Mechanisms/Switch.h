// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mechanism.h"
#include "Switch.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API ASwitch : public AMechanism
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	bool IsOn;

	UFUNCTION(BlueprintCallable)
	void OnHit(UMaterialInterface* color);
};
