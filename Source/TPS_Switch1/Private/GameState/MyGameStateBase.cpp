// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Obstacles/Chair.h"
#include "GameState/MyGameStateBase.h"

void AMyGameStateBase::SpawnObstacle(FString BPpath, FVector position, FRotator rotation)
{
    UBlueprint* BPActor = Cast<UBlueprint>(StaticLoadObject(UBlueprint::StaticClass(), nullptr, *BPpath));

    UWorld* World = GetWorld();

    if (BPActor && World)
    {
        FVector SpawnLocation = position;
        FRotator SpawnRotation = rotation;

        FTransform SpawnTransform(SpawnRotation, SpawnLocation);
        AActor* SpawnedActor = World->SpawnActor<AActor>(BPActor->GeneratedClass, SpawnTransform);
        AChair* SpawnedChair = Cast<AChair>(SpawnedActor);
        if (SpawnedChair)
        {
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("I have a chair"));

        }
        else
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("I have no chair"));
    }
}