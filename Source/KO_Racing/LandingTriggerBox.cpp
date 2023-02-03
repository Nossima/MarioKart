// Fill out your copyright notice in the Description page of Project Settings.


#include "LandingTriggerBox.h"
#include "VehiclePawn.h"

ALandingTriggerBox::ALandingTriggerBox()
{

}

void ALandingTriggerBox::BeginPlay() 
{
	Super::BeginPlay();
}

void ALandingTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (AVehiclePawn* Vehicle = Cast<AVehiclePawn>(OtherActor))
	{
		Vehicle->SetGrounded(true);
	}
}

void ALandingTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (AVehiclePawn* Vehicle = Cast<AVehiclePawn>(OtherActor))
	{
		Vehicle->SetGrounded(false);
	}
}

