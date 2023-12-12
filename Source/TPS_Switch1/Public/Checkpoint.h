// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include <BaseGameMode.h>
#include "Checkpoint.generated.h"

UCLASS()
class TPS_SWITCH1_API ACheckpoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckpoint();

	APlayerJotaro* Jotaro;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UBoxComponent* m_Box;

private:
	ABaseGameMode* m_GameMode;

public:
	UFUNCTION(BlueprintNativeEvent, Category = Event)
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnBeginOverlap_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
