// Fill out your copyright notice in the Description page of Project Settings.


#include "Checkpoint.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
	
	m_Box = GetComponentByClass<UBoxComponent>();
	m_Box->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);

	m_GameMode = Cast<ABaseGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void ACheckpoint::OnBeginOverlap_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->IsA<APlayerJotaro>() || m_GameMode->LastCheckpoint == GetActorLocation())
		return;

	m_GameMode->LastCheckpoint = GetActorLocation();
	Jotaro->Health = Jotaro->MaxHealth;
}
