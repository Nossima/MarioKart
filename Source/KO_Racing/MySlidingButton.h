// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"

#include "Engine/Texture.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

#include "MySlidingButton.generated.h"

/**
 * 
 */
UCLASS()
class KO_RACING_API UMySlidingButton : public UButton
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void Init();
	UFUNCTION(BlueprintCallable)
		void Tick(float deltaTime);
	UFUNCTION(BlueprintCallable)
		void Move(float deltaTime);
	UFUNCTION(BlueprintCallable)
		void LoadNextLevel();
	UFUNCTION(BlueprintCallable)
		void QuitGame();

	UPROPERTY(Category = Sliding, EditAnywhere, BlueprintReadWrite)
		float _timeToTransition;
	UPROPERTY(Category = Sliding, EditAnywhere, BlueprintReadWrite)
		float _speed;
	UPROPERTY(Category = Sliding, EditAnywhere, BlueprintReadWrite)
		float _maxOffset;
	UPROPERTY(Category = BtnTxt, EditAnywhere, BlueprintReadWrite)
		UTextBlock* _btnTxt;
	UPROPERTY(Category = OnClickOptional, EditAnywhere, BlueprintReadWrite)
		FString _nextLevelPath;
protected:
	float _startingX;
	float _slidedX;
	float _timer;
	bool _wasHovered;
};
