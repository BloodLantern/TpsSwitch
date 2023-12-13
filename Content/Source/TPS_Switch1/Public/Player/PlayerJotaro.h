// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBase.h"
#include "PlayerJotaro.generated.h"

class APlayerStarPlatinum;

class ABaseGameMode;

/**
 * 
 */
UCLASS()
class TPS_SWITCH1_API APlayerJotaro : public APlayerBase
{
	GENERATED_BODY()
	
public:
	APlayerJotaro();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	APlayerStarPlatinum* StarPlatinum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool IsOnPlatform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	bool ShouldJump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Health)
	float MaxHealth = 3.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Health)
	float DeathZ = -10.f;

	UFUNCTION(BlueprintImplementableEvent)
	APlayerStarPlatinum* InitializeStarPlatinum();

	void InputMovement(float Value);

private:
	ABaseGameMode* m_GameMode;

	bool m_Moving = true;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime);

	UFUNCTION(BlueprintNativeEvent, Category = Event)
	void OnAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	void OnAnyDamage_Implementation(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnDeath();
	void OnDeath_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnWin();
	void OnWin_Implementation();
};
