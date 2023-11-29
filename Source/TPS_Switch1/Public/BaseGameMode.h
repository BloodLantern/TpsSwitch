// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMaterialInterface* GetPlayerColor(int PlayerId) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMaterialInterface* GetRandomPlayerColor() const;
};
