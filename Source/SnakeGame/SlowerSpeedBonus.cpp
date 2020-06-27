// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowerSpeedBonus.h"
#include "SnakeBase.h"
#include "Engine/Engine.h"

// Sets default values
ASlowerSpeedBonus::ASlowerSpeedBonus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlowerSpeedBonus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlowerSpeedBonus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlowerSpeedBonus::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) {
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake)) {

			FString DebugMessage = FString::Printf(TEXT("Slower bonus activated!"));

			Snake->SetActorTickInterval(0.3f);
			GEngine->AddOnScreenDebugMessage(2, 4.0f, FColor::Orange, DebugMessage);
			Destroy();
		}
	}
}

