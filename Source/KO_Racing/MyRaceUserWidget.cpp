// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRaceUserWidget.h"

void UMyRaceUserWidget::ChangeRankValue(float value)
{
	_rankTxt->ChangeValue(value);
}

void UMyRaceUserWidget::ChangeLapValue(float value)
{
	_lapTxt->ChangeValue(value);
}

void UMyRaceUserWidget::ChangeSpeedValue(float value)
{
	_speedTxt->ChangeValue(value);
}

void UMyRaceUserWidget::StartTimer()
{
	_timer = 0;
	_timerIsStarted = true;
}

void UMyRaceUserWidget::StopTimer()
{
	_timerIsStarted = false;
}

void UMyRaceUserWidget::UpdateTimer(float deltaTime)
{
	if (_timerIsStarted) {
		_timer += deltaTime;
		_timerTxt->SetText(FText::FromString(FString(GenTimerString(_timer).c_str())));
	}
}

float UMyRaceUserWidget::GetTimer()
{
	return _timer;
}

std::string UMyRaceUserWidget::GenTimerString(float time)
{
	int minute = time / 60;
	int second = time - (minute * 60);
	int ms = (time - second - (minute * 60)) * 1000;
	std::string txt = "00:00.000";
	txt[0] = '0' + (minute / 10);
	txt[1] = '0' + (minute - ((minute / 10) * 10));
	txt[3] = '0' + (second / 10);
	txt[4] = '0' + (second - ((second / 10) * 10));
	txt[6] = '0' + (ms / 100);
	txt[7] = '0' + ((ms - ((ms / 100) * 100)) / 10);
	txt[8] = '0' + (ms - ((ms / 10) * 10));
	return txt;
}
