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
	bool ShouldAim = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldPunch = true;

	UFUNCTION(BlueprintCallable)
	void Aim();

	APlayerStarPlatinum();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarPlatinum)
	FVector JotaroOffset = FVector(-50.0, -50.0, 50.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StarPlatinum)
	float JotaroOffsetLerpSpeed = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
	APlayerJotaro* Jotaro;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnSpawned(APlayerJotaro* JotaroInstance);
	virtual void OnSpawned_Implementation(APlayerJotaro* JotaroInstance);

	UFUNCTION(BlueprintCallable)
	void SwapPlayers();
};
