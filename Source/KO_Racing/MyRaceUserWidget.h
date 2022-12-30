// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "MyTextBlockColorChanger.h"
#include "Components/TextBlock.h"
#include <string>

#include "MyRaceUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KO_RACING_API UMyRaceUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable)
        void ChangeRankValue(float value);
    UFUNCTION(BlueprintCallable)
        void AddLap();
    UFUNCTION(BlueprintCallable)
        void SetLapMax(float value);
    UFUNCTION(BlueprintCallable)
        void ChangeSpeedValue(float value);
    UFUNCTION(BlueprintCallable)
        void StartTimer();
    UFUNCTION(BlueprintCallable)
        void StopTimer();
    UFUNCTION(BlueprintCallable)
        void PauseTimer();
    UFUNCTION(BlueprintCallable)
        void ResumeTimer();
    UFUNCTION(BlueprintCallable)
        void UpdateTimer(float deltaTime);
    UFUNCTION(BlueprintCallable)
        float GetTimer();
    UFUNCTION(BlueprintCallable)
        TArray<float> GetLapTime();
    UFUNCTION(BlueprintCallable)
        static FString GenTimerFString(float time);

    // All my variables
    UPROPERTY(Category = TextColorChanger, EditAnywhere, BlueprintReadWrite)
        UMyTextBlockColorChanger *_rankTxt;
    UPROPERTY(Category = TextColorChanger, EditAnywhere, BlueprintReadWrite)
        UMyTextBlockColorChanger *_lapTxt;
    UPROPERTY(Category = TextColorChanger, EditAnywhere, BlueprintReadWrite)
        UMyTextBlockColorChanger *_speedTxt;
    UPROPERTY(Category = Text, EditAnywhere, BlueprintReadWrite)
        UTextBlock *_timerTxt;
protected:
    static std::string GenTimerString(float time);

    float _timer;
    bool _timerIsStarted;
    TArray<float> _lapTime;
    float _lastLapTimer = 0;
};
