// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	//Returns the WhereToSpawn Subobject
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	//Find a random point within the BoxComponent
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

	//Toggles On/Off wheter the spawn volume spawns pickups
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SetSpawningActive(bool bShouldSpawn);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//The pickup to spawn
	//TSubclassOf determines only APickupManager or its child class and blue prints
	//can be set on the what to spawn variable
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickupManager> WhatToSpawn;

	//TimerHandles can't be properties
	FTimerHandle spawnTimer;

	//Minimum spawn delay
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Spawning")
	float spawnDelayRangeLow;
	//Maximum spawn delay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float spawnDelayRangeHigh;
private:
	//Box Component to specify where pickups should be spawned 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	
	//Handles spawning a new pickup
	void SpawnPickup();

	//The current spawn delay
	float spawnDelay;
	
};
