// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMusicManagerGameInstance.h"
#include "Async/Async.h"

void UMyMusicManagerGameInstance::Init()
{
	_LastIDPlayed = -1;
	_ShouldPlay = false;
}

void UMyMusicManagerGameInstance::SetupSrc(UAudioComponent* BGMSrc)
{
	_AudioSrc = BGMSrc;
	/*_AudioSrc->bAutoActivate = false;
	_AudioSrc->bAutoDestroy = false;
	_AudioSrc->bAllowSpatialization = false;
	_AudioSrc->bIsMusic = true;
	_AudioSrc->OnAudioFinished.AddDynamic(this, &UMyMusicManagerGameInstance::PlayNextSong);*/
}

void UMyMusicManagerGameInstance::SetupList(TArray<USoundCue*> songList)
{
	_SongList = songList;
	ShuffleSongList();
}

void UMyMusicManagerGameInstance::Run()
{
	_ShouldPlay = true;
	_AudioSrc->SetSound(_SongList[++_LastIDPlayed]);
	_AudioSrc->Play();
}

void UMyMusicManagerGameInstance::Stop()
{
	_ShouldPlay = false;
}

void UMyMusicManagerGameInstance::PlayNextSong()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("World"));
	if (_ShouldPlay) {
		_AudioSrc->SetSound(_SongList[++_LastIDPlayed]);
		if (_LastIDPlayed == (_SongList.Num() - 1)) {
			_LastIDPlayed = -1;
			ShuffleSongList();
		}
		_AudioSrc->Play();
	}
}

void UMyMusicManagerGameInstance::ShuffleSongList()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("World"));
	for (int32 i = _SongList.Num() - 1; i > 0; i--) {
		int32 j = FMath::Floor(FMath::Rand() * (i + 1)) % _SongList.Num();
		_SongList.Swap(i, j);
	}
}
