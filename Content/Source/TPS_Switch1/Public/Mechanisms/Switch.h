// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mechanism.h"
#include "Bullet.h"
#include "Switch.generated.h"

/**
 *
 */
UCLASS()
class TPS_SWITCH1_API ASwitch : public AMechanism
{
	GENERATED_BODY()
public:

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	bool IsOn;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float TimeToReachPosition;

	float Timer;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector AddedOffset;

	UPROPERTY(Category = Mesh, EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* DoorMesh;

	UFUNCTION(BlueprintCallable)
	bool OnHit(UMaterialInterface* color, ABullet* bullet);

	void MoveDoor(float DeltaTime);


	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void ChooseMeshes(TArray<UStaticMeshComponent*> meshes) override;
};