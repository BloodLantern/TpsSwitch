// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerStarPlatinum.h"

APlayerStarPlatinum::APlayerStarPlatinum()
{
}

void APlayerStarPlatinum::BeginPlay()
{
	PlayerData.PlayerId = 1;

	StarBody = GetComponentByClass<USkeletalMeshComponent>();

	Super::BeginPlay();
}

void APlayerStarPlatinum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator jotaroRotation = Jotaro->GetActorRotation();
	FVector targetPosition = Jotaro->GetActorLocation() + jotaroRotation.RotateVector(JotaroOffset);
	SetActorLocation(FMath::Lerp(GetActorLocation(), targetPosition, JotaroOffsetLerpSpeed * DeltaTime));
	SetActorRotation(jotaroRotation);
}

void APlayerStarPlatinum::OnSpawned_Implementation(APlayerJotaro* JotaroInstance)
{
	Jotaro = JotaroInstance;
}

void APlayerStarPlatinum::ToggleAim_Implementation()
{
	UParticleSystemComponent* OraAura = GetComponentByClass<UParticleSystemComponent>();

	ShouldAim = !ShouldAim;

	if (OraAura)
	{
		OraAura->SetActive(ShouldAim, false);
	}
}

void APlayerStarPlatinum::MoveCursor_Implementation(FVector2D Value)
{
}

void APlayerStarPlatinum::SwapPlayers_Implementation()
{
	FPlayerData thisData = PlayerData;
	PlayerData = Jotaro->PlayerData;
	Jotaro->PlayerData = thisData;

	Jotaro->ApplyOutline();
	ApplyOutline();

	if (ShouldAim)
		ToggleAim();
}
