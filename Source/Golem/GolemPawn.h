// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GolemPawn.generated.h"

UCLASS()
class GOLEM_API AGolemPawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh;

	UFloatingPawnMovement* PawnMovement;

public:
	// Sets default values for this pawn's properties
	AGolemPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveForward();
	void MoveRight();
	void TurnAtRate();
	void LookUpRate();
	
};
