// Fill out your copyright notice in the Description page of Project Settings.


#include "FasterSpeedBonus.h"
#include "SnakeBase.h"
#include "Engine/Engine.h"

// Sets default values
AFasterSpeedBonus::AFasterSpeedBonus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFasterSpeedBonus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFasterSpeedBonus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFasterSpeedBonus::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) {
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake)) {

			FString DebugMessage = FString::Printf(TEXT("Speed bonus activated!"));

			Snake->SetActorTickInterval(0.1f);
			GEngine->AddOnScreenDebugMessage(2, 4.0f, FColor::Blue, DebugMessage);
			Destroy();
		}
	}
}

