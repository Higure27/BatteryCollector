// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//#include "Components/StaticMeshComponent.h"
#include "BatteryCollectorGameMode.generated.h"


//Enum to store the current state of gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float Deltatime) override;

	//Returns power level required to win - needed for the HUD
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin()const;

	virtual void BeginPlay() override;

	//Returns the current playing state
	UFUNCTION(BlueprintPure,Category ="Power")
	EBatteryPlayState GetCurrState() const;
	
	//Sets a new playing state
	//UFUNCTION(BlueprintPure, Category = "Power")
	void SetCurrState(EBatteryPlayState newState);

protected:
	//Ther rate at which the character loses power
	UPROPERTY(EditDefaultsOnly,BluePrintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float decayRate;

	//The power level needed to win the game
	UPROPERTY(EditDefaultsOnly, BluePrintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float powerToWin;

	//Widget class to use for the HUD scrren 
	UPROPERTY(EditDefaultsOnly, BluePrintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	//The instence of the HUD
	UPROPERTY()
	class UUserWidget* currentWidget;


private:
	//Keep track of current playing state
	EBatteryPlayState currentState;

	TArray<class ASpawnVolume*> spawnVolumeActors;

	//Handles any function calls that rely upon changing the state of the game
	void HandleNewState(EBatteryPlayState newState);

};



