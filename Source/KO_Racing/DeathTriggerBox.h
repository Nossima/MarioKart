// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "DeathTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class KO_RACING_API ADeathTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:

	ADeathTriggerBox();

	UPROPERTY(Category = Race, EditAnywhere, BlueprintReadWrite)
		FVector respawnLocation;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};
