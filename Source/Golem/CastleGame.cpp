// Fill out your copyright notice in the Description page of Project Settings.

#include "Golem.h"
#include "CastleGame.h"


void ACastleGame::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	if (world){
		world->GetGameViewport()->SetDisableSplitscreenOverride(true);
	}
}

