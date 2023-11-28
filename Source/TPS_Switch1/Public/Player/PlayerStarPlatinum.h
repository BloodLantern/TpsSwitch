// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "PlayerBase.h"
#include "Particles/ParticleSystemComponent.h"
#include "Player/PlayerJotaro.h"
#include "Animation/AnimSequence.h"
#include "PlayerStarPlatinum.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API APlayerStarPlatinum : public APlayerBase
{
	GENERATED_BODY()

public:
	//virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	APlayerJotaro* StarPlatinum;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* StarBody = GetComponentByClass<USkeletalMeshComponent>();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldAim;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldPunch;

	UFUNCTION(BlueprintCallable)
	void OnInputPressed();

	UFUNCTION(BlueprintCallable)
	void OnInputReleased();

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);
};
