// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTextBlockColorChanger.h"

#include "Styling/SlateColor.h"

void UMyTextBlockColorChanger::ChangeValue(float value)
{
	if (_oldVal == value)
		return;
	_oldVal = _currentVal;
	_currentVal = value;
	FLinearColor color;
	float maxHalf = _valMax / 2;
	if (_currentVal <= 0)
		color = _colorLow;
	else if (_currentVal < maxHalf)
		color = MixColor(_colorLow, _colorMid, (_currentVal / maxHalf));
	else if (_currentVal == maxHalf)
		color = _colorMid;
	else if (_currentVal < _valMax) {
		color = MixColor(_colorMid, _colorHigh, ((_currentVal - maxHalf) / maxHalf));
	} else
		color = _colorHigh;
	SetText(FText::FromString(FString::FromInt((int)_currentVal)));
	SetColorAndOpacity(FSlateColor(color));
}

FLinearColor UMyTextBlockColorChanger::MixColor(FLinearColor min, FLinearColor max, float mixPercent)
{
	float R = (mixPercent * (max.R - min.R)) + min.R;
	float G = (mixPercent * (max.G - min.G)) + min.G;
	float B = (mixPercent * (max.B - min.B)) + min.B;
	float A = (mixPercent * (max.A - min.A)) + min.A;
	return FLinearColor(R, G, B, A);
}
