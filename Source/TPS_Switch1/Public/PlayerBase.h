// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "PlayerData.h"
#include "PlayerBase.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TPS_SWITCH1_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBase();

	UPROPERTY(BlueprintReadWrite, Category = Player)
	FPlayerData PlayerData;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
