// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "PickupManager.generated.h"


UCLASS()
class BATTERYCOLLECTOR_API APickupManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Return the mesh for the pickup
	//Will allow to change the matriel from another class (return pickupmesh)
	//const becuase if not allowd to modify the mesh component it will just return it
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh;};


	//BluprintPure/callable are both things defined in code but can be called from Blueprints
	//BluprintPure can modify things but in general they shouldn't, on everytime they are used. 
	//Better for fast calculation that are frequent to change
	UFUNCTION(BlueprintPure,Category = "Pickup")
	//Returns if Pickup is active or not
	bool GetIsActive();
	//BlueprintCallable Only runs when execution pin is hit, saves their result in the out put pins
	//Better for expensive calculations that aren't expected to change 
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	//Allows other classes to change to activate and deactivate the Pickup
	void SetActiveState(bool newState);

	//some behavior set up in code, other in blueprints
	UFUNCTION(BlueprintNativeEvent)
	//Function to call when pickup is collected
	void WasCollected();
	//can be overwritten by any child classes
	virtual void WasCollected_Implementation();

	//can be changed within code class
	//can be changed in a blueprint 
	//can be changed in a code class based on this cureent code class 
protected:
	//True when pickup can be used.
	//False when pickup is deactivated 
	bool bIsActive;


//public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

private:
	//Statich mesh to represent pickups in the level
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
	
};
