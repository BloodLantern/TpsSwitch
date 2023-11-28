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