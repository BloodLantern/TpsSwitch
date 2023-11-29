// Fill out your copyright notice in the Description page of Project Settings.

#include "Obstacle.h"
#include "Obstacles/Chair.h"
#include "HAL/UnrealMemory.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h" 

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
    Mesh = FindComponentByClass<UStaticMeshComponent>();

    TorqueCoefficient = 500000000;
    TumbleRotation = GenerateTumbleRotation();
    Tumble();
}

void AObstacle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ApplyFallSpeed();
}

void AObstacle::SetMaterial(UMaterialInterface* material)
{
    if (Mesh)
    {
        const int32 NumMaterials = Mesh->GetNumMaterials();
        for (int32 MaterialIndex = 0; MaterialIndex < NumMaterials; ++MaterialIndex)
        {
            Mesh->SetMaterial(MaterialIndex, material);
        }
    }
    EntityData.Color = material;
}

void AObstacle::Tumble()
{

    if (Mesh && Mesh->IsSimulatingPhysics())
    {
        
        const float Pitch = FMath::DegreesToRadians(TumbleRotation.Pitch);
        const float Yaw = FMath::DegreesToRadians(TumbleRotation.Yaw);
        const float Roll = FMath::DegreesToRadians(TumbleRotation.Roll);

        const FVector Torque = FVector(Pitch, Yaw, Roll);
        Mesh->AddTorqueInRadians(Torque * TorqueCoefficient);
    }

}

FRotator AObstacle::GenerateTumbleRotation()
{
    return FRotator((FMath::RandRange(0, 100) / 100.f ) * TumbleRotationSpeed, (FMath::RandRange(0, 100) / 100.f) * TumbleRotationSpeed, (FMath::RandRange(0, 100) / 100.f) * TumbleRotationSpeed);
}

void AObstacle::ApplyFallSpeed()
{
    if (Speed == 1.0f)
    {
    }
    else if (Speed < 1.0f)
    {
        if (Mesh)
        {
            FVector FloatyForce = FVector(0.0f, 0.0f, 1.0f) * 1 / Speed;
            Mesh->AddForce(FloatyForce);
        }
    }
    else
    {
        if (Mesh)
        {
            FVector FasterFallForce = FVector(0.0f, 0.0f, -1.0f) * Speed;
            Mesh->AddForce(FasterFallForce);
        }
    }
}

void AObstacle::FocusPlayer()
{
    //Mesh->Move
}