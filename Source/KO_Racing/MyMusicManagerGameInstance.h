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

    // All my variables
    UPROPERTY(Category = Song, EditAnywhere, BlueprintReadWrite)
        TArray<USoundCue*> _SongList;
    UPROPERTY(Category = Song, EditAnywhere, BlueprintReadWrite)
        USoundCue* _CurrentSong;
    UPROPERTY(Category = Speaker, EditAnywhere, BlueprintReadWrite)
        int _LastIDPlayed;
    UPROPERTY(Category = Speaker, EditAnywhere, BlueprintReadWrite)
        bool _ShouldPlay;
    UPROPERTY(Category = Speaker, EditAnywhere, BlueprintReadWrite)
        UAudioComponent* _AudioSrc;

private:
	
};
