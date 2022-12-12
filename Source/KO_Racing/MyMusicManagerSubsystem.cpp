// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMusicManagerSubsystem.h"

void UMyMusicManagerSubsystem::Init()
{
	AudioSrc = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioSrc"));
	AudioSrc->bAutoActivate = false;
	AudioSrc->bAutoDestroy = false;
	AudioSrc->bAllowSpatialization = false;
	AudioSrc->OnAudioFinished.AddDynamic(this, &UMyMusicManagerSubsystem::PlayNextSong);
	LastIDPlayed = -1;
	ShouldPlay = false;
}

void UMyMusicManagerSubsystem::SetupList(std::vector<USoundCue*> songList)
{
	SongList = songList;
}

void UMyMusicManagerSubsystem::Run()
{
	ShouldPlay = true;
	AudioSrc->SetSound(SongList[++LastIDPlayed]);
	AudioSrc->Play();
}

void UMyMusicManagerSubsystem::Stop()
{
	ShouldPlay = false;
}

void UMyMusicManagerSubsystem::PlayNextSong()
{
	if (ShouldPlay) {
		if (LastIDPlayed == (SongList.size() - 2))
		AudioSrc->SetSound(SongList[++LastIDPlayed]);
		AudioSrc->Play();
	}
}
