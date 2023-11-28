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
        const int32 NumMaterials = ObstacleMesh->GetNumMaterials();
        for (int32 MaterialIndex = 0; MaterialIndex < NumMaterials; ++MaterialIndex)
        {
            ObstacleMesh->SetMaterial(MaterialIndex, material);
        }
    }
    EntityData.Color = material;
}

void AObstacle::Tumble()
{
    UStaticMeshComponent* MyStaticMeshComponent = FindComponentByClass<UStaticMeshComponent>();

    if (MyStaticMeshComponent && MyStaticMeshComponent->IsSimulatingPhysics())
    {
        
        float Pitch = FMath::DegreesToRadians(TumbleRotation.Pitch);
        float Yaw = FMath::DegreesToRadians(TumbleRotation.Yaw);
        float Roll = FMath::DegreesToRadians(TumbleRotation.Roll);

        FVector Torque = FVector(Pitch, Yaw, Roll);
        MyStaticMeshComponent->AddTorqueInRadians(FVector(100000, 100000, 100000));
        //should cap rotation speed as its a force that we add

    }

}

FRotator AObstacle::GenerateTumbleRotation()
{
    return FRotator(1 * TumbleRotationSpeed, 1 * TumbleRotationSpeed, 1 * TumbleRotationSpeed);
}
