// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMusicManagerGameInstance.h"

void UMyMusicManagerGameInstance::Init()
{
	/*AudioSrc = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioSrc"));
	AudioSrc->bAutoActivate = false;
	AudioSrc->bAutoDestroy = false;
	AudioSrc->bAllowSpatialization = false;
	AudioSrc->OnAudioFinished.AddDynamic(this, &UMyMusicManagerGameInstance::PlayNextSong);*/
	LastIDPlayed = -1;
	ShouldPlay = false;
}

void UMyMusicManagerGameInstance::SetupList(std::vector<USoundCue*> songList)
{
	SongList = songList;
}

void UMyMusicManagerGameInstance::Run()
{
	ShouldPlay = true;
	AudioSrc->SetSound(SongList[++LastIDPlayed]);
	AudioSrc->Play();
}

void UMyMusicManagerGameInstance::Stop()
{
	ShouldPlay = false;
}

void UMyMusicManagerGameInstance::PlayNextSong()
{
	if (ShouldPlay) {
		if (LastIDPlayed == (SongList.size() - 2))
			AudioSrc->SetSound(SongList[++LastIDPlayed]);
		AudioSrc->Play();
	}
}
