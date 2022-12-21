// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTextRotatorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KO_RACING_API UMyTextRotatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyTextRotatorComponent();

	UFUNCTION(BlueprintCallable)
		bool RotateText(FString &text, float deltaTime = -1);
	UFUNCTION(BlueprintCallable)
		FString& InitString(FString &text, int nbSpaceToAdd = -1);
	UFUNCTION(BlueprintCallable)
		FString CutToDisplay(FString text, int displayLength = -1);

	UFUNCTION(BlueprintCallable)
		void InitClass(int spaceToAdd, float timerMax, int displayLength);
	UFUNCTION(BlueprintCallable)
		void SetSpaceToAdd(int value);
	UFUNCTION(BlueprintCallable)
		void SetTimerMax(float value);
	UFUNCTION(BlueprintCallable)
		void SetDisplayLength(int value);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int _spaceToAdd;
	int _displayLength;
	float _timer;
	float _timerMax;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
