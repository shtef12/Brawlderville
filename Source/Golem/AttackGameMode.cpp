// Fill out your copyright notice in the Description page of Project Settings.

#include "Golem.h"
#include "AttackGameMode.h"



void AAttackGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	if (world){
		world->GetGameViewport()->SetDisableSplitscreenOverride(false);
	}
}
