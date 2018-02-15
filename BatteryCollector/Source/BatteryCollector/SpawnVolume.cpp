// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "BatteryCollector.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "PickupManager.h"
#include "TimerManager.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create the Box Compnent to represent the spawn volume
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	//Set the spawn delay range
	spawnDelayRangeLow = 1.0f;
	spawnDelayRangeHigh = 4.5f;

}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector spawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector spawnExtent = WhereToSpawn->Bounds.Origin;
	return UKismetMathLibrary::RandomPointInBoundingBox(spawnOrigin, spawnExtent);
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawnVolume::SetSpawningActive(bool bShouldSpawn)
{
	if (bShouldSpawn)
	{
		//Set the timer on Spawn Pickup
		spawnDelay = FMath::FRandRange(spawnDelayRangeLow, spawnDelayRangeHigh);
		//Keeps track of all timers
		//3rd: binding it to the function
		//4th: when to fire
		//5th: if to loop false/true
		GetWorldTimerManager().SetTimer(spawnTimer, this, &ASpawnVolume::SpawnPickup, spawnDelay, false);
	}
	else
	{
		//clear the timer on Spawn Pickup
		GetWorldTimerManager().ClearTimer(spawnTimer);

	}
}

void ASpawnVolume::SpawnPickup()
{
	//If we have set something to spawn:
	if(WhatToSpawn != NULL)
	{ 
		//Check for a valid World:
		UWorld* const world = GetWorld();
		if (world)
		{
			//Set the spawn parameters
			FActorSpawnParameters spawnParams;
			//Objects acknowledging what spawned and owns them
			spawnParams.Owner = this;
			spawnParams.Instigator = Instigator;

			//Get a random location to spawn at
			FVector spawnLocation = GetRandomPointInVolume();

			//Get a random rotation
			FRotator spawnRotation;
			spawnRotation.Yaw = FMath::FRand() * 360.0f;
			spawnRotation.Pitch = FMath::FRand() * 360.0f;
			spawnRotation.Roll = FMath::FRand() * 360.0f;

			//spawn the pickup
			APickupManager* const spawnedPickup = world->SpawnActor<APickupManager>(WhatToSpawn, spawnLocation, spawnRotation, spawnParams);

			spawnDelay = FMath::FRandRange(spawnDelayRangeLow, spawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(spawnTimer, this, &ASpawnVolume::SpawnPickup, spawnDelay, false);
		}

	}

}

// Called every frame
/*void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}*/

