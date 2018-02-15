// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "BatteryCollector.h"
#include "BatteryPickup.h"

//set defult value 
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);

	//Base power level of the battery
	batteryPower = 150.0f;
}


void ABatteryPickup::WasCollected_Implementation()
{
	//Use the base pickup behaviour -parent function:super
	Super::WasCollected_Implementation();
	UE_LOG(LogClass, Log, TEXT("about to be destroyed"));
	//Destroy the battery
	Destroy();
	UE_LOG(LogClass, Log, TEXT("Battery Collected"));
}

float ABatteryPickup::GetPower()
{
	return batteryPower;
}
