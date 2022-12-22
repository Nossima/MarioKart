// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMusicManagerGameInstance.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include <string>
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

/*void Test(UMyMusicManagerGameInstance* UMMMGI)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Test World"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString(("start sleeping for " + std::to_string(UMMMGI->_CurrentSong->Duration) + "s").c_str()));
	FPlatformProcess::Sleep(UMMMGI->_CurrentSong->Duration);
	std::this_thread::sleep_for(std::chrono::seconds((int)(UMMMGI->_CurrentSong->Duration) + 1));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("I'm awake now"));
	//PlayNextSong();
	while (UMMMGI->_ShouldPlay) {
		UMMMGI->_CurrentSong = UMMMGI->_SongList[++(UMMMGI->_LastIDPlayed)];
		//_AudioSrc->Stop();
		//_AudioSrc->SetSound(_CurrentSong);
		if (UMMMGI->_LastIDPlayed == (UMMMGI->_SongList.Num() - 1)) {
			UMMMGI->_LastIDPlayed = -1;
			UMMMGI->ShuffleSongList();
		}
		//_AudioSrc->Play(0);
		UGameplayStatics::CreateSound2D(UMMMGI, UMMMGI->_CurrentSong, 1.000000, 1.000000, 0.000000, ((USoundConcurrency*)nullptr), true, true)->Play(0);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString(("start sleeping for " + std::to_string(UMMMGI->_CurrentSong->Duration) + "s").c_str()));
		FPlatformProcess::Sleep(UMMMGI->_CurrentSong->Duration);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("I'm awake now"));
	}
}*/

void UMyMusicManagerGameInstance::Init()
{
	_LastIDPlayed = -1;
	_ShouldPlay = false;
}

void UMyMusicManagerGameInstance::SetupList(TArray<USoundCue*> songList)
{
	_SongList = songList;
	ShuffleSongList();
}

void UMyMusicManagerGameInstance::InitRadio()
{
	ShuffleSongList();
	_LastIDPlayed = -1;
	_ShouldPlay = true;
}

void UMyMusicManagerGameInstance::StopRadio()
{
	_AudioSrc->Stop();
	_ShouldPlay = false;
}

void UMyMusicManagerGameInstance::PlayNextSong()
{
	_CurrentSong = _SongList[++_LastIDPlayed];
	if (_LastIDPlayed == (_SongList.Num() - 1)) {
		_LastIDPlayed = -1;
		ShuffleSongList();
	}
	_AudioSrc = UGameplayStatics::CreateSound2D(this, _CurrentSong, 1.000000, 1.000000, 0.000000, ((USoundConcurrency*)nullptr), true, true);
	//_AudioSrc->OnAudioFinished.AddDynamic(this, &UMyMusicManagerGameInstance::PlayNextSong);
	_AudioSrc->Play(0);
}

void UMyMusicManagerGameInstance::ShuffleSongList()
{
	for (int32 i = _SongList.Num() - 1; i > 0; i--) {
		int32 j = FMath::Floor(FMath::Rand() * (i + 1)) % _SongList.Num();
		_SongList.Swap(i, j);
	}
}