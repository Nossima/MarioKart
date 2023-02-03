// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRaceUserWidget.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include <iostream>

void UMyRaceUserWidget::Init()
{
	_speedTxt->ChangeValue(0);
	_rankTxt->ChangeValue(0);
	_lapTxt->ChangeValue(1);
	SetLapMax(3);
	_beforeStartTimerTxt->ChangeValue(3);
	_pauseTxt->SetVisibility(ESlateVisibility::Hidden);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->InputComponent->BindAction("PauseAction", IE_Pressed, this, &UMyRaceUserWidget::TogglePause).bExecuteWhenPaused = true;
	_playerPawn = (AVehiclePawn*)UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	_scoreboardBackground->SetVisibility(ESlateVisibility::Hidden);
	_scoreboardTitle->SetVisibility(ESlateVisibility::Hidden);
	_scoreboardTxt->SetVisibility(ESlateVisibility::Hidden);
}

void UMyRaceUserWidget::ChangeRankValue(float value)
{
	_rankTxt->ChangeValue(value);
}

void UMyRaceUserWidget::AddLap()
{
	_lapTxt->ChangeValue(_lapTxt->_currentVal + 1);
	_lapTime.Add(_timer - _lastLapTimer);
	_lastLapTimer = _timer;
	if (_lapTxt->_currentVal == _lapTxt->_valMax)
		DisplayScoreboard();
}

void UMyRaceUserWidget::SetLapMax(float value)
{
	_lapTxt->_valMax = value;
}

void UMyRaceUserWidget::ChangeSpeedValue(float value)
{
	_speedTxt->ChangeValue(value);
}

void UMyRaceUserWidget::StartTimer()
{
	_timer = 0;
	_beforeStart = 3;
	_timerIsStarted = true;
	_beforeStartPaused = false;
}

void UMyRaceUserWidget::StopTimer()
{
	_timerIsStarted = false;
	_lapTime.Add(_timer - _lastLapTimer);
	_lastLapTimer = _timer;
}

void UMyRaceUserWidget::PauseTimer()
{
	_timerIsStarted = false;
}

void UMyRaceUserWidget::ResumeTimer()
{
	_timerIsStarted = true;
}

void UMyRaceUserWidget::UpdateTimer(float deltaTime)
{
	if (_timerIsStarted) {
		if (_beforeStart <= 0) {
			_timer += deltaTime;
			_timerTxt->SetText(FText::FromString(GenTimerFString(_timer)));
		} else {
			if (!_beforeStartPaused) {
				_beforeStartPaused = true;
				UGameplayStatics::SetGamePaused(GetWorld(), true);
			}
			_beforeStart -= deltaTime;
			_beforeStartTimerTxt->ChangeValue(_beforeStart + 1);
			if (_beforeStart <= 0) {
				_beforeStartPaused = false;
				_raceAsStarted = true;
				_beforeStartTimerTxt->SetVisibility(ESlateVisibility::Hidden);
				UGameplayStatics::SetGamePaused(GetWorld(), false);
			}
		}
	}
}

void UMyRaceUserWidget::UpdateSpeed(float deltaTime)
{
	ChangeSpeedValue(_playerPawn->GetVelocity().Size());
}

float UMyRaceUserWidget::GetTimer()
{
	return _timer;
}

TArray<float> UMyRaceUserWidget::GetLapTime()
{
	return _lapTime;
}

FString UMyRaceUserWidget::GenTimerFString(float time)
{
	return FString(GenTimerString(time).c_str());
}

void UMyRaceUserWidget::TogglePause()
{
	_isPaused = !_isPaused;
	_pauseTxt->SetVisibility((_isPaused) ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	(!_isPaused) ? ResumeTimer() : PauseTimer();
	UGameplayStatics::SetGamePaused(GetWorld(), _isPaused);
}

void UMyRaceUserWidget::DisplayScoreboard()
{
	StopTimer();
	_scoreboardBackground->SetVisibility(ESlateVisibility::Visible);
	_scoreboardTitle->SetVisibility(ESlateVisibility::Visible);
	_scoreboardTxt->SetVisibility(ESlateVisibility::Visible);
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	std::string scoreStr = "Total: " + GenTimerString(_timer) + "\n\n";
	for (int i = 0; i < _lapTime.Num(); ++i)
		scoreStr += std::to_string(i + 1) + " : " + GenTimerString(_lapTime[i]) + "\n";
	_scoreboardTxt->SetText(FText::FromString(FString(scoreStr.c_str())));
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
