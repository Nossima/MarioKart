// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMusicManagerSetUpper.h"
#include "Kismet/GameplayStatics.h"
#include "MyMusicManagerGameInstance.h"

// Sets default values
AMyMusicManagerSetUpper::AMyMusicManagerSetUpper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyMusicManagerSetUpper::BeginPlay()
{
	Super::BeginPlay();
	_BGMSrc = FindComponentByClass<UAudioComponent>();
	//UMyMusicManagerGameSubsystem *GI = GEngine->GetEngineSubsystem<UMyMusicManagerGameSubsystem>();
	UMyMusicManagerGameInstance *GI = Cast<UMyMusicManagerGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GI->SetupSrc(_BGMSrc);
	GI->SetupList(_SongList);
	GI->Run();
}

// Called every frame
void AMyMusicManagerSetUpper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

