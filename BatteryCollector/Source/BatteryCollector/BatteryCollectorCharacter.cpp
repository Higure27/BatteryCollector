// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "PickupManager.h"
#include "BatteryPickup.h"


//////////////////////////////////////////////////////////////////////////
// ABatteryCollectorCharacter

ABatteryCollectorCharacter::ABatteryCollectorCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Create the Collection Sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	//AttachTo is deprecated, can also use 
	//AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform) instead.
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(200.0f);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	//Set a base power level for the character
	initialPower = 2000.0f;
	characterCurrPower = initialPower;

	//set the dependce of speed to power level 
	speedFactor = .75f;
	baseSpeed = 10.0f;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABatteryCollectorCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	InputComponent->BindAction("Collect", IE_Pressed, this, &ABatteryCollectorCharacter::CollectPickups);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABatteryCollectorCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABatteryCollectorCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABatteryCollectorCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABatteryCollectorCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ABatteryCollectorCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ABatteryCollectorCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ABatteryCollectorCharacter::OnResetVR);
}


void ABatteryCollectorCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ABatteryCollectorCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ABatteryCollectorCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ABatteryCollectorCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABatteryCollectorCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABatteryCollectorCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ABatteryCollectorCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

//Collect anypickup touching the characters collection sphere
//If their batteries add their power level to character
void ABatteryCollectorCharacter::CollectPickups()
{
	//Get all overlapping Actors and store them in an array
	TArray<AActor*> collectedActors;
	CollectionSphere->GetOverlappingActors(collectedActors);

	//keep track of collected power
	float collectedPower = 0;

	//For each actor we collected
	for (int32 iCollected = 0; iCollected < collectedActors.Num(); iCollected++)
	{	
		//Cast the actor to APickup
		APickupManager* const testPickup = Cast<APickupManager>(collectedActors[iCollected]);
		//If the cast is successful and the pickup is valid and active
		if (testPickup && !testPickup->IsPendingKill() && testPickup->GetIsActive())
		{
			UE_LOG(LogClass, Log, TEXT("about to collect"));
			//Call the pickup's WasCollected function
			testPickup->WasCollected();
			UE_LOG(LogClass, Log, TEXT("collected"));

			//Check if the pickp is also a battery
			ABatteryPickup* const testBattery = Cast<ABatteryPickup>(testPickup);
			if (testBattery)
			{
				//Increase Collected power
				collectedPower += testBattery->GetPower();
			}


			//Deactivate the pickup
			testPickup->SetActiveState(false);
		}
	}
	//Updates the Character's Power level using power level 
	//Collected from batteries
	if (collectedPower > 0)
	{
		UpdatePower(collectedPower);
		//Make sure not to go over character's max power 
		/*if (collectedPower + characterCurrPower >=initialPower)
		{
			UpdatePower(initialPower - characterCurrPower);
		}
		else
		{
			//UpdatePower(collectedPower);
		}*/
		
	}
}

//Returns starting power
float ABatteryCollectorCharacter::GetInitialPower()
{
	return initialPower;
}

//Returns current power
float ABatteryCollectorCharacter::GetCurrPower()
{
	return characterCurrPower;
}

//called whenever powers is either decreased or increased
void ABatteryCollectorCharacter::UpdatePower(float powerChange)
{
	//Updated current power level
	characterCurrPower += powerChange;
	//Update character's movment speed based on  current power
	GetCharacterMovement()->MaxWalkSpeed = baseSpeed + speedFactor * characterCurrPower;
	//Call visual effect 
	PowerChangeEffect();
}