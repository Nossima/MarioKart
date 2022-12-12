// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"
#include <vector>
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "MyMusicManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class KO_RACING_API UMyMusicManagerSubsystem : public UGameInstance
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

    void SetupList(std::vector<USoundCue*> songList);
    void Run();
    void Stop();

private:
    void PlayNextSong();
    // All my variables
    // Song variables
    std::vector<USoundCue*> SongList;
    int LastIDPlayed;
    bool ShouldPlay;
    // Audio source variables
    UAudioComponent* AudioSrc;
};
