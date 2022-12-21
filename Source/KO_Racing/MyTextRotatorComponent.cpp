// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTextRotatorComponent.h"
#include <string>

// Sets default values for this component's properties
UMyTextRotatorComponent::UMyTextRotatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	InitClass(0, 0, 0);

	// ...
}

bool UMyTextRotatorComponent::RotateText(FString& text, float deltaTime)
{

	if (deltaTime != -1)
		_timer += deltaTime;
	if (deltaTime == -1 || _timer >= _timerMax) {
		std::string tmpStr = std::string(TCHAR_TO_UTF8(*text));
		tmpStr.append(1, text[0]).erase(0, 1);
		text = FString(tmpStr.c_str());
		return true;
	}
	else
		return false;
}

FString& UMyTextRotatorComponent::InitString(FString& text, int nbSpaceToAdd)
{
	text = FString(std::string(TCHAR_TO_UTF8(*text)).append((nbSpaceToAdd != -1) ? nbSpaceToAdd : _spaceToAdd, ' ').c_str());
	return text;
}

FString UMyTextRotatorComponent::CutToDisplay(FString text, int displayLength)
{
	return FString(std::string(TCHAR_TO_UTF8(*text)).substr(0, (displayLength != -1) ? displayLength : _displayLength).c_str());
}

void UMyTextRotatorComponent::InitClass(int spaceToAdd, float timerMax, int displayLength)
{
	SetSpaceToAdd(spaceToAdd);
	SetTimerMax(timerMax);
	SetDisplayLength(displayLength);
	_timer = 0;
}

void UMyTextRotatorComponent::SetSpaceToAdd(int value)
{
	_spaceToAdd = value;
}

void UMyTextRotatorComponent::SetTimerMax(float value)
{
	_timerMax = value;
}

void UMyTextRotatorComponent::SetDisplayLength(int value)
{
	_displayLength = value;
}


// Called when the game starts
void UMyTextRotatorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyTextRotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

