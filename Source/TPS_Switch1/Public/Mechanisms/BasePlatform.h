// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mechanism.h"
#include "../../Public/Player/PlayerJotaro.h"
#include "BasePlatform.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API ABasePlatform : public AMechanism
{
	GENERATED_BODY()
	ABasePlatform();
public:

	UFUNCTION(BlueprintCallable)
	void OnHit(APlayerJotaro* player);


protected:
	virtual void BeginPlay() override;

private:
	UStaticMeshComponent* m_Mesh;
};
