// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTextBlockRotator.h"


bool UMyTextBlockRotator::RotateText(float deltaTime)
{
	_timer += deltaTime;
	if (_timer >= _timerMax) {
		_currentString.append(1, _currentString[0]).erase(0, 1);
		_timer = 0;
		return true;
	}
	else
		return false;
}



FText UMyTextBlockRotator::CutToDisplay()
{
	return FText::FromString(FString(_currentString.substr(0, _displayLength).c_str()));
}

void UMyTextBlockRotator::RotateCurrent(float deltaTime)
{
	RotateText(deltaTime);
	SetText(CutToDisplay());
}

void UMyTextBlockRotator::InitClass(int spaceToAdd, float timerMax, int displayLength)
{
	SetSpaceToAdd(spaceToAdd);
	SetTimerMax(timerMax);
	SetDisplayLength(displayLength);
	_timer = 0;
}

void UMyTextBlockRotator::InitString(FString textToAssign)
{
	_currentString = std::string(TCHAR_TO_UTF8(*textToAssign));
	ReplaceAll(_currentString, "Cue", "");
	ReplaceAll(_currentString, "_", " ");
	_currentString.append(_spaceToAdd, ' ');
}

void UMyTextBlockRotator::SetSpaceToAdd(int value)
{
	_spaceToAdd = value;
}

void UMyTextBlockRotator::SetTimerMax(float value)
{
	_timerMax = value;
}

void UMyTextBlockRotator::SetDisplayLength(int value)
{
	_displayLength = value;
}

std::size_t UMyTextBlockRotator::ReplaceAll(std::string& inout, std::string what, std::string with)
{
	std::size_t count{};
	for (std::string::size_type pos{};
		inout.npos != (pos = inout.find(what.data(), pos, what.length()));
		pos += with.length(), ++count) {
		inout.replace(pos, what.length(), with.data(), with.length());
	}
	return count;
}