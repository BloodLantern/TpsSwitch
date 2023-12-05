// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechanisms/Switch.h"

void ASwitch::BeginPlay()
{
	Super::BeginPlay();
	Timer = TimeToReachPosition;
}


void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Timer > 0 && IsOn)
	{
		MoveDoor(DeltaTime);
	}
}

void ASwitch::OnHit(UMaterialInterface* color, ABullet* bullet)
{
	if (bullet->EntityData.Color == EntityData.Color)
	{
		if (!IsOn)
		{
			IsOn = true;
			Mesh->SetMaterial(0, color);
		}
	}
}

void ASwitch::MoveDoor(float DeltaTime)
{
	DoorMesh->SetRelativeLocation(DoorMesh->GetRelativeLocation() + AddedOffset / TimeToReachPosition * DeltaTime);
	Timer -= DeltaTime;
}