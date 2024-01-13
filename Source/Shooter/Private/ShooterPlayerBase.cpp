// Shooter game. All rights reserved!

#include "ShooterCharacterMovementCom.h"
#include "Shooter/Public/ShooterPlayerBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AShooterPlayerBase::AShooterPlayerBase(const FObjectInitializer& ObjectInit) : Super(ObjectInit.SetDefaultSubobjectClass<UShooterCharacterMovementCom>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);
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
	PlayerInputComponent->BindAxis("TurnTop",  this,  &AShooterPlayerBase::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &AShooterPlayerBase::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AShooterPlayerBase::Jump);
	//ускорение бинд функцый
	PlayerInputComponent->BindAction("Run" , IE_Pressed, this, &AShooterPlayerBase::StarRunning);
	PlayerInputComponent->BindAction("Run" , IE_Released, this, &AShooterPlayerBase::StopRunning);
}

bool AShooterPlayerBase::IsRunning()
{
	return (WantRunning && IsMoveForward && !GetVelocity().IsZero());
}

void AShooterPlayerBase::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);

	IsMoveForward = Amount > 0.05;
}

void AShooterPlayerBase::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}


//ускорение функцый
void AShooterPlayerBase::StarRunning()
{
	WantRunning = true;
}

void AShooterPlayerBase::StopRunning()
{
	WantRunning = false;
}

/*
	void AShooterPlayerBase::TurnTop(float Amount)
{
	AddControllerPitchInput(Amount);
}
void AShooterPlayerBase::TurnAround(float Amount)
{
	AddControllerYawInput(Amount);
}
*/
