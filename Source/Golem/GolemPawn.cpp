// Fill out your copyright notice in the Description page of Project Settings.

#include "Golem.h"
#include "GolemPawn.h"


// Sets default values
AGolemPawn::AGolemPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMovement"));
	PawnMovement->UpdatedComponent = Mesh;
}

// Called when the game starts or when spawned
void AGolemPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGolemPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGolemPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AGolemPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AGolemPawn::MoveRight);
	InputComponent->BindAxis("Turn", this, &AGolemPawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AGolemPawn::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &AGolemPawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AGolemPawn::LookUpRate);


}

void AGolemPawn::MoveForward(float val)
{
	if (val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
		}
	}
}

void AGolemPawn::MoveRight(float val)
{
	if (val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Val);
		}
	}
}

void AGolemPawn::TurnAtRate(float rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
}

void AGolemPawn::LookUpRate(float rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
}

void AGolemPawn::LookUp(float val)
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->AddPitchInput(Val);
	}
}