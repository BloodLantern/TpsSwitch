// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/GameUserSettings.h"
#include "JojoPlayerController.h"
#include <EnhancedInputSubsystems.h>

APlayerStarPlatinum* ABaseGameMode::CreatePlayer1(FTransform Transform)
{
	UGameplayStatics::CreatePlayer(GetWorld(), 0);
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	AddMappingContext(controller);

	APlayerJotaro* jotaro = SpawnJotaro(Transform);
	controller->Possess(jotaro);

	return jotaro->InitializeStarPlatinum();
}

void ABaseGameMode::CreatePlayer2(APlayerStarPlatinum* StarPlatinum)
{
	APlayerController* controller = UGameplayStatics::CreatePlayer(GetWorld(), 1);

	AddMappingContext(controller);

	AJojoPlayerController* jojoController = Cast<AJojoPlayerController>(controller);
	jojoController->PlayerId = 1;

	controller->Possess(StarPlatinum);
}

void ABaseGameMode::BeginPlay()
{
	// Enable VSync
	UGameUserSettings::GetGameUserSettings()->bUseVSync = true;

	// There is only one PlayerStart in the level
	TArray<AActor*> playerStarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), playerStarts);

	APlayerStarPlatinum* starPlatinum = CreatePlayer1(playerStarts[0]->GetActorTransform());
	CreatePlayer2(starPlatinum);
}

void ABaseGameMode::Tick(float DeltaTime)
{
	TotalGameTime += DeltaTime;
}

UMaterialInterface* ABaseGameMode::GetPlayerColor(int PlayerId) const
{
	return PlayerColors[PlayerId];
}

UMaterialInterface* ABaseGameMode::GetRandomPlayerColor() const
{
	return GetPlayerColor(FMath::RandHelper(PlayerColors.Num()));
}
