// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/GameUserSettings.h"
#include "JojoPlayerController.h"
#include "Checkpoint.h"
#include <EnhancedInputSubsystems.h>

void ABaseGameMode::CreatePlayer1(FTransform Transform)
{
	// Player 1 already exists, so CreatePlayer will return nullptr
	UGameplayStatics::CreatePlayer(GetWorld(), 0);
	// Manually get its player controller
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	AddMappingContext(controller);

	PlayerJotaro = SpawnJotaro(Transform);
	controller->Possess(PlayerJotaro);
}

void ABaseGameMode::CreatePlayer2()
{
	APlayerController* controller = UGameplayStatics::CreatePlayer(GetWorld(), 1);
	// If player 2 already exists, get its player controller instead
	if (!controller)
		controller = UGameplayStatics::GetPlayerController(GetWorld(), 1);

	AddMappingContext(controller);

	AJojoPlayerController* jojoController = Cast<AJojoPlayerController>(controller);
	jojoController->PlayerId = 1;

	controller->Possess(PlayerJotaro->InitializeStarPlatinum());
}

void ABaseGameMode::CreatePlayers(FTransform Transform)
{
	CreatePlayer1(Transform);
	CreatePlayer2();
}

void ABaseGameMode::BeginPlay()
{
	// Enable VSync
	UGameUserSettings::GetGameUserSettings()->bUseVSync = true;

	// There is only one PlayerStart in the level
	TArray<AActor*> playerStarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), playerStarts);

	FTransform playerStart = playerStarts[0]->GetActorTransform();
	CreatePlayers(playerStart);
	SetupPlayerOutlines();

	LastCheckpoint = playerStart.GetLocation();

	TArray<AActor*> checkpoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACheckpoint::StaticClass(), checkpoints);

	for (AActor* checkpoint : checkpoints)
		Cast<ACheckpoint>(checkpoint)->Jotaro = PlayerJotaro;
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
