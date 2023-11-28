// Fill out your copyright notice in the Description page of Project Settings.

#include "Obstacle.h"
#include "Obstacles/Chair.h"
#include "HAL/UnrealMemory.h"

AObstacle::AObstacle()
{
    PrimaryActorTick.bCanEverTick = true;
}

AObstacle::~AObstacle()
{
}

void AObstacle::BeginPlay()
{
    Super::BeginPlay();
    TumbleRotation = GenerateTumbleRotation();
}

void AObstacle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Tumble();
}

void AObstacle::SetMaterial(UMaterialInterface* material)
{
    if (UStaticMeshComponent* ObstacleMesh = FindComponentByClass<UStaticMeshComponent>())
    {
        int32 NumMaterials = ObstacleMesh->GetNumMaterials();
        for (int32 MaterialIndex = 0; MaterialIndex < NumMaterials; ++MaterialIndex)
        {
            ObstacleMesh->SetMaterial(MaterialIndex, material);
        }
    }
    EntityData.Color = material;
}

void AObstacle::Tumble()
{
    FQuat QuatRotation = FQuat(TumbleRotation);

    AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

FRotator AObstacle::GenerateTumbleRotation()
{
    return  FRotator(float(FMath::RandRange(0, 100)) / 100 * TumbleRotationSpeed, float(FMath::RandRange(0, 100)) / 100 * TumbleRotationSpeed, float(FMath::RandRange(0, 100)) / 100 * TumbleRotationSpeed);
}
