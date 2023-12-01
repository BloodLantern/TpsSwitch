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

void ABasePlatform::OnHit(APlayerJotaro* player)
{
	if (EntityData.Color == player->PlayerData.Color)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, EntityData.Color->GetFName().ToString());
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, player->PlayerData.Color->GetFName().ToString());
		m_Mesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	}
}

