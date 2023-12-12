// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Player/PlayerJotaro.h"
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API ABaseGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
	TArray<UMaterialInterface*> PlayerColors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
	APlayerJotaro* PlayerJotaro;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Time)
	float TotalGameTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Time)
	FVector LastCheckpoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	bool InMenus;

private:
	APlayerStarPlatinum* CreatePlayer1(FTransform Transform);
	void CreatePlayer2(APlayerStarPlatinum* StarPlatinum);

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	APlayerJotaro* SpawnJotaro(FTransform Transform);

	UFUNCTION(BlueprintImplementableEvent)
	void AddMappingContext(APlayerController* PlayerController);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMaterialInterface* GetPlayerColor(int PlayerId) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMaterialInterface* GetRandomPlayerColor() const;
};
