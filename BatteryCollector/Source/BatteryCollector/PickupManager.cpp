// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupManager.h"
#include "BatteryCollector.h"
//#include "Components/StaticMeshComponent.h"



// Sets default values
APickupManager::APickupManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	//All Pickups start active
	bIsActive = true;

	//Create the static mesh component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	//Effect and such will be based on the size of the pickup mesh
	RootComponent = PickupMesh;

}

// Called when the game starts or when spawned
void APickupManager::BeginPlay()
{
	Super::BeginPlay();
	
}

//Returns Active state
bool APickupManager::GetIsActive()
{
	return bIsActive;
}

//Changes Active state
void APickupManager::SetActiveState(bool newState)
{
	bIsActive = newState;
}
void APickupManager::WasCollected_Implementation()
{
	UE_LOG(LogClass, Log, TEXT("in implement"))
	// Log a debug messege
	FString pickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *pickupDebugString);
}
// Called every frame
/*void APickupManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

