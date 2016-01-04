// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CastleGame.generated.h"

/**
 * 
 */
UCLASS()
class GOLEM_API ACastleGame : public AGameMode
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
	
	
};
