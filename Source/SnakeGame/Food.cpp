// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "SnakeBase.h"
#include "Engine/Engine.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	valuePitch = 0.0f;
	valueYaw = 0.0f;
	valueRoll = 0.0f;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator bananaRotation = FRotator(valuePitch, valueYaw, valueRoll);
	FQuat quatRotation = FQuat(bananaRotation);

	AddActorLocalRotation(quatRotation, false, 0, ETeleportType::None);

}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) {
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake)) {

			FString DebugMessage = FString::Printf(TEXT("Banana is eaten!"));

			Snake->AddSnakeElement();
			GEngine->AddOnScreenDebugMessage(2, 4.0f, FColor::Yellow, DebugMessage);
			Destroy();
		}
	}
}

