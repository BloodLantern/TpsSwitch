// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerStarPlatinum.h"

/*void APlayerStarPlatinum::BeginPlay()
{

}*/

void APlayerStarPlatinum::OnInputPressed()
{
    UParticleSystemComponent* OraAura = GetComponentByClass<UParticleSystemComponent>();
    
    if (OraAura)
    {
        OraAura->SetActive(true, false);
    }

    ShouldPunch = false;
    ShouldAim = true;
}

void APlayerStarPlatinum::OnInputReleased()
{
    UParticleSystemComponent* OraAura = GetComponentByClass<UParticleSystemComponent>();

    if (OraAura)
    {
        OraAura->SetActive(false, true);
    }

    ShouldAim = false;
    ShouldPunch = true;
}


void APlayerStarPlatinum::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &APlayerStarPlatinum::OnInputPressed);
    PlayerInputComponent->BindAction("Aim", IE_Released, this, &APlayerStarPlatinum::OnInputReleased);
}
APlayerStarPlatinum::APlayerStarPlatinum()
{
}

void APlayerStarPlatinum::BeginPlay()
{
	PlayerData.PlayerId = 1;

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

void APlayerStarPlatinum::SwapPlayers()
{
	FPlayerData thisData = PlayerData;
	PlayerData = Jotaro->PlayerData;
	Jotaro->PlayerData = thisData;
}
