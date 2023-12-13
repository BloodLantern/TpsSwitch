// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "EnhancedInputSubsystems.h"
#include "BaseGameMode.h"

// Sets default values
APlayerBase::APlayerBase()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void APlayerBase::ApplyOutline()
{
    GetMesh()->SetOverlayMaterial(PlayerData.Outline);
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
    Super::BeginPlay();

    if (ABaseGameMode* gameMode = Cast<ABaseGameMode>(GetWorld()->GetAuthGameMode()))
        PlayerData.Color = gameMode->GetPlayerColor(PlayerData.PlayerId);
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
