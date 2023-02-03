// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveSetting.generated.h"

#define SETTING_SAVE_SLOT_NAME TEXT("SETTING")

/**
 * 
 */
UCLASS()
class KO_RACING_API UMySaveSetting : public USaveGame
{
	GENERATED_BODY()
	
public:
	//UMySaveSetting();

	UPROPERTY(Category = Sound, EditAnywhere, BlueprintReadWrite)
		float _musicVolume = 1;
	UPROPERTY(Category = Sound, EditAnywhere, BlueprintReadWrite)
		float _FXVolume = 1;
};
