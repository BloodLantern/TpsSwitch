// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanisms/BasePlatform.h"
#include "Components/StaticMeshComponent.h" 

ABasePlatform::ABasePlatform()
{
}

void ABasePlatform::BeginPlay()
{
	Super::BeginPlay();
	m_Mesh = FindComponentByClass<UStaticMeshComponent>();
}




void ABasePlatform::BeginHit(APlayerJotaro* player)
{
	if (EntityData.Color == player->PlayerData.Color)
	{
		m_Mesh->SetCollisionProfileName(TEXT("BlockAll"));
	}
}

void ABasePlatform::OnHit(APlayerJotaro* player)
{
	player->IsOnPlatform = true;
}

void ABasePlatform::OutBox(APlayerJotaro* player)
{
	player->IsOnPlatform = false;
}

void ABasePlatform::DisableCollision(APlayerJotaro* player)
{
	if (player->IsOnPlatform)
		if (player->PlayerData.Color != EntityData.Color)
			m_Mesh->SetCollisionProfileName(TEXT("OverlapAll"));
}