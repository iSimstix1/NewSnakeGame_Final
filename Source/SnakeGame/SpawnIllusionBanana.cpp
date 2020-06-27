// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnIllusionBanana.h"
#include "SnakeBase.h"
#include "Food.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "cstdlib"

// Sets default values
ASpawnIllusionBanana::ASpawnIllusionBanana()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	valuePitch = 0.0f;
	valueYaw = 0.0f;
	valueRoll = 0.0f;
}

// Called when the game starts or when spawned
void ASpawnIllusionBanana::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnIllusionBanana::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator illusionBananaRotating = FRotator(valuePitch, valueYaw, valueRoll);

	FQuat quatRotation = FQuat(illusionBananaRotating);
	AddActorLocalRotation(quatRotation, false, 0, ETeleportType::None);

}

void ASpawnIllusionBanana::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) {
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake)) {

			FString DebugMessage = FString::Printf(TEXT("The illusion of a banana?"));
			GEngine->AddOnScreenDebugMessage(2, 4.0f, FColor::Purple, DebugMessage);

			SpawnIllusionBanana();
			Destroy();
		}
	}
}

void ASpawnIllusionBanana::SpawnIllusionBanana()
{
	GetWorld()->SpawnActor<ASpawnIllusionBanana>(ActorToSpawn, FVector(randFloat(-200.0f, -600.0f), randFloat(-500.0f, 500.0f), -8.0f), FRotator());
}

double ASpawnIllusionBanana::randFloat(double M, double N)
{
	return M + (rand() / (RAND_MAX / (N - M)));
}

