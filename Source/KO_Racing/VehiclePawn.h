// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehiclePawn.generated.h"

/**
 *
 */
UCLASS()
class KO_RACING_API AVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	AVehiclePawn();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void GiveBonus(int BonusType);
	UPROPERTY(Category = Bonus, EditAnywhere, BlueprintReadOnly)
		int bonus;

	void SetGrounded(bool groundedVal);
	UPROPERTY(Category = Race, EditAnywhere, BlueprintReadOnly)
		int grounded;

	UPROPERTY(Category = Race, EditAnywhere, BlueprintReadWrite)
		float waterLevel;

	// Throttle & Steering
	void ApplyThrottle(float Val);
	void ApplySteering(float Val);

	// Camera mouse input
	void Lookup(float Val);
	void Turn(float Val);

	// Handbrake
	void OnHandbrakePressed();
	void OnHandbrakeReleased();

	// Respawn
	void setRespawnLocation(FVector LocToSave);
	FVector getRespawnLocation();
	void clearMovement();

	// Lap
	void increaseLap();
	UFUNCTION(Category = Race, BlueprintCallable, BlueprintPure)
		int getCurrentLap();
	UPROPERTY(Category = Race, EditAnywhere, BlueprintReadOnly)
		int maxCurrentLap = 3;

	// EndGame + Timer
	void endGame();
	void startTimer();

	UPROPERTY(Category = Timer, EditDefaultsOnly, BlueprintReadOnly)
		int seconds;



	// Tire variables
	UPROPERTY(Category = Tire, EditDefaultsOnly, BlueprintReadOnly)
		float MinTireLoad = 0.0f;
	UPROPERTY(Category = Tire, EditDefaultsOnly, BlueprintReadOnly)
		float MinTireLoadFiltered = 0.2f;
	UPROPERTY(Category = Tire, EditDefaultsOnly, BlueprintReadOnly)
		float MaxTireLoad = 2.0f;
	UPROPERTY(Category = Tire, EditDefaultsOnly, BlueprintReadOnly)
		float MaxTireLoadFiltered = 2.0f;

	// Torque variables
	UPROPERTY(Category = Torque, EditDefaultsOnly, BlueprintReadOnly)
		float MaxEngineRPM = 5700.0f;
	UPROPERTY(Category = Torque, EditDefaultsOnly, BlueprintReadOnly)
		float FirstTorqueMin = 0.0f;
	UPROPERTY(Category = Torque, EditDefaultsOnly, BlueprintReadOnly)
		float FirstTorqueMax = 400.0f;
	UPROPERTY(Category = Torque, EditDefaultsOnly, BlueprintReadOnly)
		float SecondTorqueMin = 1890.0f;
	UPROPERTY(Category = Torque, EditDefaultsOnly, BlueprintReadOnly)
		float SecondTorqueMax = 500.0f;
	UPROPERTY(Category = Torque, EditDefaultsOnly, BlueprintReadOnly)
		float ThirdTorqueMin = 5730.0f;
	UPROPERTY(Category = Torque, EditDefaultsOnly, BlueprintReadOnly)
		float ThirdTorqueMax = 400.0f;

	// Steering variables
	UPROPERTY(Category = Sterring, EditDefaultsOnly, BlueprintReadOnly)
		float FirstSteeringMin = 0.0f;
	UPROPERTY(Category = Sterring, EditDefaultsOnly, BlueprintReadOnly)
		float FirstSteeringMax = 1.0f;
	UPROPERTY(Category = Sterring, EditDefaultsOnly, BlueprintReadOnly)
		float SecondSteeringMin = 40.0f;
	UPROPERTY(Category = Sterring, EditDefaultsOnly, BlueprintReadOnly)
		float SecondSteeringMax = 0.7f;
	UPROPERTY(Category = Sterring, EditDefaultsOnly, BlueprintReadOnly)
		float ThirdSteeringMin = 120.0f;
	UPROPERTY(Category = Sterring, EditDefaultsOnly, BlueprintReadOnly)
		float ThirdSteeringMax = 0.6f;

	// Gearbox variables
	UPROPERTY(Category = Gearbox, EditDefaultsOnly, BlueprintReadOnly)
		bool GearAutoBox = true;
	UPROPERTY(Category = Gearbox, EditDefaultsOnly, BlueprintReadOnly)
		float GearSwitchTime = 0.15f;
	UPROPERTY(Category = Gearbox, EditDefaultsOnly, BlueprintReadOnly)
		float GearAutoBoxLatency = 1.0f;

	// Air Physics
	void UpdateInAirControl(float DeltaTime);

protected:

	// Spring arm for camera
	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccedd = "true"))
		class USpringArmComponent* SpringArm;

	// Camera
	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccedd = "true"))
		class UCameraComponent* Camera;

private:
	FVector RespawnLocation;
	int currentLap = 0;
};
