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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	APlayerStarPlatinum* StarPlatinum;

	UFUNCTION(BlueprintImplementableEvent)
	void InputCamera(const FVector2D& Value);

	UFUNCTION(BlueprintImplementableEvent)
	void InputMovement(const FVector2D& Value);

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
