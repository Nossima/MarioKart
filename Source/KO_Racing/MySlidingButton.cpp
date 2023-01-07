// Fill out your copyright notice in the Description page of Project Settings.


#include "MySlidingButton.h"

void UMySlidingButton::Init()
{
	_startingX = RenderTransform.Translation.X;
	_slidedX = _startingX - _maxOffset;
	_timer = 0;
}

void UMySlidingButton::Tick(float deltaTime)
{
	Move(deltaTime);
}

void UMySlidingButton::Move(float deltaTime)
{
	if (IsHovered()) {
		if (!_wasHovered) {
			_timer = 0;
			_wasHovered = true;
		}
		_timer += deltaTime;
		if (_timer < _timeToTransition) {
			FVector2D btnTxtPos = _btnTxt->RenderTransform.Translation;
			FVector2D btnPos = RenderTransform.Translation;
			float resX = (btnPos.X - _slidedX) * (_timer / _timeToTransition);
			btnTxtPos.X += resX;
			btnPos.X -= resX;
			_btnTxt->SetRenderTranslation(btnTxtPos);
			SetRenderTranslation(btnPos);
		} else {
			FVector2D btnTxtPos = _btnTxt->RenderTransform.Translation;
			FVector2D btnPos = RenderTransform.Translation;
			float resX = btnPos.X - _slidedX;
			btnTxtPos.X += resX;
			btnPos.X -= resX;
			_btnTxt->SetRenderTranslation(btnTxtPos);
			SetRenderTranslation(btnPos);
		}
	} else {
		if (_wasHovered) {
			_timer = 0;
			_wasHovered = false;
		}
		_timer += deltaTime;
		if (_timer < _timeToTransition) {
			FVector2D btnTxtPos = _btnTxt->RenderTransform.Translation;
			FVector2D btnPos = RenderTransform.Translation;
			float resX = (_startingX - btnPos.X) * (_timer / _timeToTransition);
			btnTxtPos.X -= resX;
			btnPos.X += resX;
			_btnTxt->SetRenderTranslation(btnTxtPos);
			SetRenderTranslation(btnPos);
		} else {
			FVector2D btnTxtPos = _btnTxt->RenderTransform.Translation;
			FVector2D btnPos = RenderTransform.Translation;
			float resX = _startingX - btnPos.X;
			btnTxtPos.X -= resX;
			btnPos.X += resX;
			_btnTxt->SetRenderTranslation(btnTxtPos);
			SetRenderTranslation(btnPos);
		}
	}
}

void UMySlidingButton::LoadNextLevel()
{
	GetWorld()->ServerTravel(_nextLevelPath);
}

void UMySlidingButton::QuitGame()
{
	FGenericPlatformMisc::RequestExit(false);
}
