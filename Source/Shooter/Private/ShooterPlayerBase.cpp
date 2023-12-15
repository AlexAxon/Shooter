// Shooter game. All rights reserved!


#include "Shooter/Public/ShooterPlayerBase.h"
#include "Camera/CameraComponent.h"

// Sets default values
AShooterPlayerBase::AShooterPlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AShooterPlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterPlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterPlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AShooterPlayerBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AShooterPlayerBase::MoveRight);
}

void AShooterPlayerBase::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AShooterPlayerBase::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

