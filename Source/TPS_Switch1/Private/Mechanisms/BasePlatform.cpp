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
	if (EntityData.Color != player->PlayerData.Color)
	{
		m_Mesh->SetCollisionProfileName(TEXT("OverlapAll"));
	}
}