// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerJotaro.h"
#include "Player/PlayerStarPlatinum.h"
#include <JojoPlayerController.h>
#include <BaseGameMode.h>
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

APlayerJotaro::APlayerJotaro()
	: Health(MaxHealth)
{
}

void APlayerJotaro::InputMovement(float Value)
{
	// Move horizontally
	AddMovementInput(UKismetMathLibrary::GetRightVector(GetControlRotation()), Value);
}

void APlayerJotaro::BeginPlay()
{
	Super::BeginPlay();

	PlayerData.PlayerId = 0;

	m_GameMode = Cast<ABaseGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	OnTakeAnyDamage.AddDynamic(this, &ThisClass::OnAnyDamage);
}

void APlayerJotaro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Always move forward
	if (m_Moving)
		AddMovementInput(UKismetMathLibrary::GetForwardVector(GetControlRotation()), 1.f);

	if (GetActorLocation().Z <= DeathZ)
		UGameplayStatics::ApplyDamage(this, 1.f, GetController(), this, nullptr);
}

void APlayerJotaro::OnAnyDamage_Implementation(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Health -= Damage;
	SetActorLocation(m_GameMode->LastCheckpoint);

	if (Health <= 0)
		OnDeath();
}

void APlayerJotaro::OnDeath_Implementation()
{
	m_Moving = false;
}

void APlayerJotaro::OnWin_Implementation()
{
	m_Moving = false;
}
