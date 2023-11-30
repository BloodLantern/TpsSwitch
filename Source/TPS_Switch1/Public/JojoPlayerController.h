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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* CameraAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SlideAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SwapPlayersAction;
	
protected:
	virtual void OnPossess(APawn* aPawn) override;

	virtual void SetupInputComponent() override;

private:
	void InputCamera(const FInputActionValue& Value);
	void InputMovement(const FInputActionValue& Value);
	void InputJump();
	void InputSlide();
	void InputAim();
	void InputSwapPlayers();
};
