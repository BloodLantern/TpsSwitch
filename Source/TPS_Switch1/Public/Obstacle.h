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

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int HP;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FEntityData EntityData;

	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterialInterface* material);

protected:
	virtual void BeginPlay() override;

};
