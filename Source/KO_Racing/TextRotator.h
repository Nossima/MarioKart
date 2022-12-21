// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>

/**
 * 
 */
class KO_RACING_API TextRotator
{
public:
	TextRotator();
	TextRotator(int spaceToAdd, float timerMax, int displayLength);
	~TextRotator();

	bool RotateText(std::string &text, float deltaTime = -1);
	std::string& InitString(std::string& text, int nbSpaceToAdd = -1);
	std::string CutToDisplay(std::string text, int displayLength = -1);

	void InitClass(int spaceToAdd, float timerMax, int displayLength);
	void SetSpaceToAdd(int value);
	void SetTimerMax(float value);
	void SetDisplayLength(int value);


protected:
	int _spaceToAdd;
	int _displayLength;
	float _timer;
	float _timerMax;
};
