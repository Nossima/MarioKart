// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMusicManagerGameInstance.h"

#include "GenericPlatform/GenericPlatformProcess.h"
#include <string>
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

/*void Test(UMyMusicManagerGameInstance* UMMMGI)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Test World"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString(("start sleeping for " + std::to_string(UMMMGI->_currentSong->Duration) + "s").c_str()));
	FPlatformProcess::Sleep(UMMMGI->_currentSong->Duration);
	std::this_thread::sleep_for(std::chrono::seconds((int)(UMMMGI->_currentSong->Duration) + 1));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("I'm awake now"));
	//PlayNextSong();
	while (UMMMGI->_shouldPlay) {
		UMMMGI->_currentSong = UMMMGI->_songList[++(UMMMGI->_lastIDPlayed)];
		//_AudioSrc->Stop();
		//_AudioSrc->SetSound(_currentSong);
		if (UMMMGI->_lastIDPlayed == (UMMMGI->_songList.Num() - 1)) {
			UMMMGI->_lastIDPlayed = -1;
			UMMMGI->ShuffleSongList();
		}
		//_AudioSrc->Play(0);
		UGameplayStatics::CreateSound2D(UMMMGI, UMMMGI->_currentSong, 1.000000, 1.000000, 0.000000, ((USoundConcurrency*)nullptr), true, true)->Play(0);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString(("start sleeping for " + std::to_string(UMMMGI->_currentSong->Duration) + "s").c_str()));
		FPlatformProcess::Sleep(UMMMGI->_currentSong->Duration);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("I'm awake now"));
	}
}*/

void UMyMusicManagerGameInstance::Init()
{
	_lastIDPlayed = -1;
	_shouldPlay = false;
	LoadSetting();
}

void UMyMusicManagerGameInstance::Shutdown()
{
	SaveSetting();
}

void UMyMusicManagerGameInstance::SetupList(TArray<USoundCue*> songList)
{
	_songList = songList;
	ShuffleSongList();
}

void UMyMusicManagerGameInstance::InitRadio()
{
	ShuffleSongList();
	_lastIDPlayed = -1;
	_shouldPlay = true;
}

void UMyMusicManagerGameInstance::StopRadio()
{
	_audioSrc->Stop();
	_shouldPlay = false;
}

void UMyMusicManagerGameInstance::PlayNextSong()
{
	_currentSong = _songList[++_lastIDPlayed];
	if (_lastIDPlayed == (_songList.Num() - 1)) {
		_lastIDPlayed = -1;
		ShuffleSongList();
	}
	_audioSrc = UGameplayStatics::CreateSound2D(this, _currentSong, _setting->_musicVolume, 1.000000, 0.000000, ((USoundConcurrency*)nullptr), true, true);
	_audioSrc->Play(0);
}

void UMyMusicManagerGameInstance::ShuffleSongList()
{
	for (int32 i = _songList.Num() - 1; i > 0; i--) {
		int32 j = FMath::Floor(FMath::Rand() * (i + 1)) % _songList.Num();
		_songList.Swap(i, j);
	}
}

void UMyMusicManagerGameInstance::ChangeMusicVolume(float value)
{
	_setting->_musicVolume = value;
	_audioSrc->SetVolumeMultiplier(_setting->_musicVolume);
}

void UMyMusicManagerGameInstance::ChangeFXVolume(float value)
{
	_setting->_FXVolume = value;
}

void UMyMusicManagerGameInstance::SaveSetting()
{
	// Call SaveGameToSlot to serialize and save our SaveGameObject with name: <SaveGameSlotName>.sav
	const bool IsSaved = UGameplayStatics::SaveGameToSlot(_setting, SETTING_SAVE_SLOT_NAME, 0);
}

void UMyMusicManagerGameInstance::LoadSetting()
{
	// Try to load a saved game file (with name: <SaveGameSlotName>.sav) if exists
	USaveGame* LoadedGame = UGameplayStatics::LoadGameFromSlot(SETTING_SAVE_SLOT_NAME, 0);
	_setting = Cast<UMySaveSetting>(LoadedGame);
	// If file does not exist try create a new one
	if (!_setting)
	{
		// Instantiate a new SaveGame object
		_setting = Cast<UMySaveSetting>(UGameplayStatics::CreateSaveGameObject(UMySaveSetting::StaticClass()));
		// Call SaveGameToSlot to serialize and save our SaveGameObject with name: <SaveGameSlotName>.sav
		const bool IsSaved = UGameplayStatics::SaveGameToSlot(_setting, SETTING_SAVE_SLOT_NAME, 0);
	}
}
