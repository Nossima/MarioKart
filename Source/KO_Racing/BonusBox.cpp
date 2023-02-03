// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusBox.h"
#include "VehiclePawn.h"

// Sets default values
ABonusBox::ABonusBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ABonusBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ABonusBox::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ABonusBox::BeginPlay()
{
	Super::BeginPlay();

}

void ABonusBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (AVehiclePawn* Vehicle = Cast<AVehiclePawn>(OtherActor))
	{
		
	}
}

void ABonusBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
}

