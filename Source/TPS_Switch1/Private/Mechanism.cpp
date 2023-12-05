// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanism.h"

// Sets default values
AMechanism::AMechanism()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMechanism::BeginPlay()
{
	Super::BeginPlay();

	TArray<UActorComponent*> staticMeshComponents = GetComponentsByClass(UStaticMeshComponent::StaticClass());
	TArray<UStaticMeshComponent*> meshes;

	for (UActorComponent* staticMesh : staticMeshComponents)
	{
		if (UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(staticMesh))
			meshes.Add(mesh);
	}

	ChooseMeshes(meshes);

	EntityData.Color = Mesh->GetMaterial(0);
}

void AMechanism::ChooseMeshes(TArray<UStaticMeshComponent*> meshes)
{
	if (meshes.Num() == 1)
		Mesh = meshes[0];
}

// Called every frame
void AMechanism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
