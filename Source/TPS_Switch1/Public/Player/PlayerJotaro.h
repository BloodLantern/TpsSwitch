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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool IsOnPlatform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation)
	bool ShouldJump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation)
	bool ShouldSlide;

	UFUNCTION(BlueprintImplementableEvent)
	APlayerStarPlatinum* InitializeStarPlatinum();

	void InputMovement(float Value);

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime);
};
