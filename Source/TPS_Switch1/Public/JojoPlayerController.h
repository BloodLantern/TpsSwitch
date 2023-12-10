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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	int PlayerId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
	APlayerJotaro* Jotaro;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	APlayerStarPlatinum* StarPlatinum;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TSoftObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SlideAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveCursorAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SwapPlayersAction;
	
protected:
	virtual void OnPossess(APawn* aPawn) override;

	virtual void SetupInputComponent() override;

private:
	void InputMovement(const FInputActionValue& Value);
	void InputJumpBegin();
	void InputJumpEnd();
	void InputSlideBegin();
	void InputSlideEnd();
	void InputAim();
	void InputMoveCursor();
	void InputSwapPlayers();
};
