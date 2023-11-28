// Fill out your copyright notice in the Description page of Project Settings.

#include "Obstacle.h"
#include "Obstacles/Chair.h"
#include "HAL/UnrealMemory.h"

AObstacle::AObstacle()
{
}

AObstacle::~AObstacle()
{
}

void AObstacle::BeginPlay()
{
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
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Obstacle mesh component not found in AObstacle"));
    }
    EntityData.Color = material;
}
