// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "SpawnIllusionBanana.generated.h"

UCLASS()
class SNAKEGAME_API ASpawnIllusionBanana : public AActor, public IInteractable
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, Category = Movement)
		float valuePitch;
	UPROPERTY(EditAnyWhere, Category = Movement)
		float valueYaw;
	UPROPERTY(EditAnyWhere, Category = Movement)
		float valueRoll;

	UPROPERTY(EditAnyWhere)
		TSubclassOf<ASpawnIllusionBanana> ActorToSpawn;
public:	
	// Sets default values for this actor's properties
	ASpawnIllusionBanana();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	void SpawnIllusionBanana();

	double randFloat(double A, double B);
};
