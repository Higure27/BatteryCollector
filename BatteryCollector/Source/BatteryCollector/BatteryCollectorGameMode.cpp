// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "SpawnVolume.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
//#include "Components/StaticMeshComponent.h"
#include "Engine/SkeletalMesh.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	UE_LOG(LogClass, Log, TEXT("constructed"));
	//Base decay rate
	decayRate = .01f;
	
	//https://answers.unrealengine.com/questions/558892/gamemode-not-firing-tick.html
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;

}

void ABatteryCollectorGameMode::BeginPlay()
{
	Super::BeginPlay();

	//Find all spawn volume actors
	TArray<AActor*> foundActors;
	//Better for small scale, with samll number of actors
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), foundActors);

	for (auto actor : foundActors)
	{
		ASpawnVolume* spawnVolumeActor = Cast<ASpawnVolume>(actor);
		if (spawnVolumeActor)
		{
			spawnVolumeActors.AddUnique(spawnVolumeActor);
		}
	}


	SetCurrState(EBatteryPlayState::EPlaying);

	//set score to beat
	ABatteryCollectorCharacter* myCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	//Checking cast is valid
	if (myCharacter)
	{
		powerToWin = (myCharacter->GetInitialPower())*1.25f;
	}

	if (HUDWidgetClass != nullptr)
	{
		currentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (currentWidget != nullptr)
		{
			currentWidget->AddToViewport();
		}
	}

}

void ABatteryCollectorGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Checking Battery collector character is being using,using a cast
	//UE_LOG(LogClass, Log, TEXT("You have collected"));
	ABatteryCollectorCharacter* myCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	//Checking cast is valid
	if (myCharacter)
	{
		//If poer level is greater than the amount needed to win
		//Set state to won 
		if (myCharacter->GetCurrPower() > powerToWin)
		{
			SetCurrState(EBatteryPlayState::EWon);
		}
		//if character's power is positive
		else if (myCharacter->GetCurrPower() > 0)
		{
			//decrease power using decay rate
			myCharacter->UpdatePower(-DeltaTime * decayRate*(myCharacter->GetInitialPower()));
		}
		else
		{
			SetCurrState(EBatteryPlayState::EGameOver);
		}

	}
}

float ABatteryCollectorGameMode::GetPowerToWin() const
{
	return powerToWin;
}

EBatteryPlayState ABatteryCollectorGameMode::GetCurrState() const
{
	return currentState;
}

void ABatteryCollectorGameMode::SetCurrState(EBatteryPlayState newState)
{
	//set current state
	currentState = newState;
	//Handle new state
	HandleNewState(currentState);
}

void ABatteryCollectorGameMode::HandleNewState(EBatteryPlayState newState)
{
	switch (newState)
	{
		//If the game is playing
		case EBatteryPlayState::EPlaying:
		{
			//SpawnVolumes are active
			for (ASpawnVolume* volume : spawnVolumeActors)
			{
				volume->SetSpawningActive(true);
			}
		}
		break;
		//If game is won
		case EBatteryPlayState::EWon:
		{
			//SpawnVolumes are inactive
			//SpawnVolumes are active
			for (ASpawnVolume* volume : spawnVolumeActors)
			{
				volume->SetSpawningActive(false);
			}
		}
		break;
		//If game is lost
		case EBatteryPlayState::EGameOver:
		{
			//SpawnVolumes are inactive
			for (ASpawnVolume* volume : spawnVolumeActors)
			{
				volume->SetSpawningActive(false);
			}

			//block player input
			APlayerController* playerContorller = UGameplayStatics::GetPlayerController(this,0);
			if (playerContorller)
			{
				playerContorller->SetCinematicMode(true, false, false, true, true);
			}
			//ragdoll the character
			ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
			if (myCharacter)
			{
				//Ragdoll
				myCharacter->GetMesh()->SetSimulatePhysics(true);
				myCharacter->GetMovementComponent()->MovementState.bCanJump = false;
			}
		}
		break;
		//Uknown: for debugging
		default:
		case EBatteryPlayState::EUnknown:
		{

		}
		break;
	}
}
