// Fill out your copyright notice in the Description page of Project Settings.


#include "TextRotator.h"

TextRotator::TextRotator()
{
	_spaceToAdd = 0;
	_displayLength = 0;
	_timerMax = 0;
	_timer = 0;
}

TextRotator::TextRotator(int spaceToAdd, float timerMax, int displayLength)
{
	InitClass(spaceToAdd, timerMax, displayLength);
}

TextRotator::~TextRotator()
{
}

bool TextRotator::RotateText(std::string& text, float deltaTime)
{
	if (deltaTime != -1)
		_timer += deltaTime;
	if (deltaTime == -1 || _timer >= _timerMax) {
		text.append(1, text[0]).erase(0, 1);
		return true;
	} else
		return false;
}

std::string& TextRotator::InitString(std::string& text, int nbSpaceToAdd)
{
	return text.append((nbSpaceToAdd != -1) ? nbSpaceToAdd : _spaceToAdd, ' ');
}

std::string TextRotator::CutToDisplay(std::string text, int displayLength)
{
	return text.substr(0, (displayLength != -1) ? displayLength : _displayLength);
}

void TextRotator::InitClass(int spaceToAdd, float timerMax, int displayLength)
{
	SetSpaceToAdd(spaceToAdd);
	SetTimerMax(timerMax);
	SetDisplayLength(displayLength);
	_timer = 0;
}

void TextRotator::SetSpaceToAdd(int value)
{
	_spaceToAdd = value;
}

void TextRotator::SetTimerMax(float value)
{
	_timerMax = value;
}

void TextRotator::SetDisplayLength(int value)
{
	_displayLength = value;
}
