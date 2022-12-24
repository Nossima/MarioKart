// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"

#include "Math/Color.h"

#include "MyTextBlockColorChanger.generated.h"

/**
 * 
 */
UCLASS()
class KO_RACING_API UMyTextBlockColorChanger : public UTextBlock
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable)
        void ChangeValue(float value);
    UFUNCTION(BlueprintCallable)
        static FLinearColor MixColor(FLinearColor min, FLinearColor max, float mixPercent);

    // All my variables
    UPROPERTY(Category = Color, EditAnywhere, BlueprintReadWrite)
        FLinearColor _colorLow;
    UPROPERTY(Category = Color, EditAnywhere, BlueprintReadWrite)
        FLinearColor _colorMid;
    UPROPERTY(Category = Color, EditAnywhere, BlueprintReadWrite)
        FLinearColor _colorHigh;
    UPROPERTY(Category = ValueLimit, EditAnywhere, BlueprintReadWrite)
        float _valMax;
    UPROPERTY(Category = Value, EditAnywhere, BlueprintReadWrite)
        float _currentVal;
    UPROPERTY(Category = Value, EditAnywhere, BlueprintReadWrite)
        float _oldVal;
};
