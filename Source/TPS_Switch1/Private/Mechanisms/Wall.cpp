// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanisms/Wall.h"

void AWall::BeginPlay()
{
	Super::BeginPlay();
	m_Mesh = FindComponentByClass<UStaticMeshComponent>();
}

void AWall::BeginHit(APlayerJotaro* player)
{
	if (EntityData.Color == player->PlayerData.Color)
	{
		player->SetActorLocation(FVector(500, 500, 500));
	}
}