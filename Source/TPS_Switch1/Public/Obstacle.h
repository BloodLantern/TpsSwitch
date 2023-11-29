// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntityData.h"
#include "Obstacle.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API AObstacle : public AActor
{
	GENERATED_BODY()
public:
	AObstacle();
	~AObstacle() noexcept;

	UStaticMeshComponent* Mesh;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int HP;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float Speed;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float TumbleRotationSpeed;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FEntityData EntityData;

	FRotator TumbleRotation;
	bool Landed;

	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterialInterface* material);
	void Tumble();
	FRotator GenerateTumbleRotation();
	void ApplyFallSpeed();
	void FocusPlayer();


	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
private:
	int TorqueCoefficient;
	float GravityScaleFactor;
};
