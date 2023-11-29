// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <Player/PlayerJotaro.h>
#include <Player/PlayerStarPlatinum.h>
#include "JojoPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API AJojoPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
	APlayerJotaro* Jotaro;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	APlayerStarPlatinum* StarPlatinum;
	
protected:
	virtual void OnPossess(APawn* aPawn) override;

	virtual void SetupInputComponent() override;

private:
	void InputAimPressed();
	void InputAimReleased();
};
