// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EntityData.h"
#include "Mechanism.generated.h"

UCLASS()
class TPS_SWITCH1_API AMechanism : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMechanism();

	UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FEntityData EntityData;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
