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
    m_TorqueCoefficient = 50000;
    m_RandomPrecision = 100;
    TumbleRotation = GenerateTumbleRotation();
    //Tumble();
}

void AObstacle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //ApplyFallSpeed();
    FocusPlayer();
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
        Mesh->AddTorqueInRadians(Torque * m_TorqueCoefficient, NAME_None, true);
    }
}

FRotator AObstacle::GenerateTumbleRotation()
{
    return FRotator((FMath::RandRange(0, m_RandomPrecision) / float(m_RandomPrecision)) * TumbleRotationSpeed, (FMath::RandRange(0, m_RandomPrecision) / float(m_RandomPrecision)) * TumbleRotationSpeed, (FMath::RandRange(0, m_RandomPrecision) / float(m_RandomPrecision)) * TumbleRotationSpeed);
}

void AObstacle::ApplyFallSpeed()
{
    if (Speed < 1.0f)
    {
        if (Mesh)
        {
            FVector FloatyForce = FVector::UpVector * 1 / Speed;
            Mesh->AddForce(FloatyForce, NAME_None, true);
        }
    }
    else
    {
        if (Mesh)
        {
            FVector FasterFallForce = FVector::DownVector * Speed;
            Mesh->AddForce(FasterFallForce, NAME_None, true);
        }
    }
}

void AObstacle::FocusPlayer()
{
    FVector DirectionToPlayer = (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation()).GetSafeNormal();
    float DistanceToPlayer = FVector::Dist(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(), GetActorLocation());
    float MaxForce = 1000.0f;
    float ForceMagnitude = FMath::Clamp(MaxForce, 0.0f, MaxForce);
    FVector Force = DirectionToPlayer * ForceMagnitude;
    Mesh->AddForce(Force, NAME_None, true);
}

void AObstacle::GetDamaged(int damage)
{
    HP -= damage;
    if (HP <= 0)
    {
        Destroy();
    }
}
