// Fill out your copyright notice in the Description page of Project Settings.

#include "Mechanisms/Switch.h"

void ASwitch::BeginPlay()
{
	Super::BeginPlay();
	Timer = TimeToReachPosition;
}

void ASwitch::ChooseMeshes(TArray<UStaticMeshComponent*> meshes)
{
	for (UStaticMeshComponent* mesh : meshes)
	{
		if (mesh->GetFName() == "Door")
			DoorMesh = mesh;
		else if (mesh->GetFName() == "Switch")
			Mesh = mesh;
	}
}

void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Timer > 0 && IsOn)
	{
		MoveDoor(DeltaTime);
	}
}

bool ASwitch::OnHit(UMaterialInterface* color, ABullet* bullet)
{
	if (bullet->EntityData.Color == EntityData.Color)
	{
		if (!IsOn)
		{
			IsOn = true;
			Mesh->SetMaterial(0, color);

			return true;
		}
	}

	return false;
}

void ASwitch::MoveDoor(float DeltaTime)
{
	DoorMesh->SetRelativeLocation(DoorMesh->GetRelativeLocation() + AddedOffset / TimeToReachPosition * DeltaTime);
	Timer -= DeltaTime;
}