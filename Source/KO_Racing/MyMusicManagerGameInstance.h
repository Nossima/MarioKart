// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Containers/Array.h"
#include "MySaveSetting.h"

#include "MyMusicManagerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class KO_RACING_API UMyMusicManagerGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    // Begin USubsystem
    /*virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;*/
    // End USubsystem

    // Begin UGameInstance
    virtual void Init() override;
    virtual void Shutdown() override;
    // End UGameInstance

    UFUNCTION(BlueprintCallable)
        void SetupList(TArray<USoundCue*> songList);
    UFUNCTION(BlueprintCallable)
        void InitRadio();
    UFUNCTION(BlueprintCallable)

        void StopRadio();
    UFUNCTION(BlueprintCallable)
        void PlayNextSong();
    UFUNCTION(BlueprintCallable)
        void ShuffleSongList();

    UFUNCTION(BlueprintCallable)
        void ChangeMusicVolume(float value);
    UFUNCTION(BlueprintCallable)
        void ChangeFXVolume(float value);

    UFUNCTION(BlueprintCallable)
        void SaveSetting();
    UFUNCTION(BlueprintCallable)
        void LoadSetting();

    // All my variables
    UPROPERTY(Category = Song, EditAnywhere, BlueprintReadWrite)
        TArray<USoundCue*> _songList;
    UPROPERTY(Category = Song, EditAnywhere, BlueprintReadWrite)
        USoundCue* _currentSong;
    UPROPERTY(Category = Speaker, EditAnywhere, BlueprintReadWrite)
        int _lastIDPlayed;
    UPROPERTY(Category = Speaker, EditAnywhere, BlueprintReadWrite)
        bool _shouldPlay;
    UPROPERTY(Category = Speaker, EditAnywhere, BlueprintReadWrite)
        UAudioComponent* _audioSrc;
    UPROPERTY(Category = Setting, EditAnywhere, BlueprintReadWrite)
        UMySaveSetting *_setting;

private:
	
};
