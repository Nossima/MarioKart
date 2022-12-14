// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include <vector>
#include "Sound/SoundCue.h"
#include "Containers/Array.h"
#include "MyMusicManagerSetUpper.generated.h"

UCLASS()
class KO_RACING_API AMyMusicManagerSetUpper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyMusicManagerSetUpper();

	void Test();

	UPROPERTY(Category = BGM, EditAnywhere)
		TArray<USoundCue*> _SongList;
	UPROPERTY(Category = BGM, EditAnywhere)
		class UAudioComponent *_BGMSrc;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};