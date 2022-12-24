// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <string>
#include "Components/TextBlock.h"

#include "MyTextBlockRotator.generated.h"

/**
 * 
 */
UCLASS()
class KO_RACING_API UMyTextBlockRotator : public UTextBlock
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		bool RotateText(float deltaTime);
	UFUNCTION(BlueprintCallable)
		FText CutToDisplay();
	UFUNCTION(BlueprintCallable)
		void RotateCurrent(float deltaTime);

	UFUNCTION(BlueprintCallable)
		void InitClass(int spaceToAdd, float timerMax, int displayLength);
	UFUNCTION(BlueprintCallable)
		void InitString(FString textToAssign);
	UFUNCTION(BlueprintCallable)
		void SetSpaceToAdd(int value);
	UFUNCTION(BlueprintCallable)
		void SetTimerMax(float value);
	UFUNCTION(BlueprintCallable)
		void SetDisplayLength(int value);

	static std::size_t ReplaceAll(std::string& inout, std::string what, std::string with);

protected:
	int _spaceToAdd;
	int _displayLength;
	float _timer;
	float _timerMax;
	std::string _currentString;
};
