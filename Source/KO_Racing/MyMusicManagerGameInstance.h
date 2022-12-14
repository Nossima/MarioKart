// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Containers/Array.h"
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
    // End UGameInstance

    void SetupSrc(UAudioComponent* BGMSrc);
    void SetupList(TArray<USoundCue*> songList);
    void Run();
    void Stop();
    void PlayNextSong();
    void ShuffleSongList();

private:
    // All my variables
    // Song variables
    TArray<USoundCue*> _SongList;
    USoundCue* _CurrentSong;
    int _LastIDPlayed;
    bool _ShouldPlay;
    // Audio source variables
    UAudioComponent* _AudioSrc;
	
};
