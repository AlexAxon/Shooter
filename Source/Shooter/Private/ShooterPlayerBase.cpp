// Shooter game. All rights reserved!

#include "Shooter/Public/ShooterPlayerBase.h"
#include "ShooterHealthComponent.h"
#include "ShooterCharacterMovementCom.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Controller.h"
#include "ShooterWeaponBase.h"
#include "WaeponComponent.h"
#include "Engine/DamageEvents.h"
#include "Components/CapsuleComponent.h"


DEFINE_LOG_CATEGORY_STATIC(LogHealth,All,All)
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
	HealthComponent = CreateDefaultSubobject<UShooterHealthComponent>("ShooterHealthComponent");
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComponent");
	TextRenderComponent->SetupAttachment(GetRootComponent());
	WeaponComponent = CreateDefaultSubobject<UWaeponComponent>("WeaponComponent");
}

// Called when the game starts or when spawned
void AShooterPlayerBase::BeginPlay()
{
	Super::BeginPlay();
	OnHealthChange(HealthComponent->GetHealth());
	HealthComponent->OnDeath.AddUObject(this,&AShooterPlayerBase::OnDeath);
	HealthComponent->OnHealthChange.AddUObject(this,&AShooterPlayerBase::OnHealthChange);
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
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AShooterPlayerBase::StarRunning);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AShooterPlayerBase::StopRunning);
	PlayerInputComponent->BindAction("Fire",IE_Pressed,WeaponComponent,&UWaeponComponent::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, WeaponComponent, &UWaeponComponent::StopFire);
}

bool AShooterPlayerBase::IsRunning()
{
	return (WantRunning && IsMoveForward && !GetVelocity().IsZero());
}

float AShooterPlayerBase::GetMovementDirection()
{
	if(GetVelocity().IsZero()) return 0.0f;
	auto VelocityNormal = GetVelocity().GetSafeNormal();
	auto Angel = FMath::Acos(FVector::DotProduct(GetActorForwardVector(),VelocityNormal));
	auto CrossProduct = FVector::CrossProduct(VelocityNormal,GetActorForwardVector());
	auto Degrees = FMath::RadiansToDegrees(Angel);
	return CrossProduct.IsZero() ? Degrees : Degrees * FMath::Sign(CrossProduct.Z);
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

void AShooterPlayerBase::OnDeath()
{
	PlayAnimMontage(DeathAnimMontage);
	GetCharacterMovement()->DisableMovement();
	SetLifeSpan(5);
	UE_LOG(LogHealth,Display, TEXT("Player IS Dead!"));
	if (Controller)
	{
		Controller->ChangeState(NAME_Spectating);
	}
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
}

void AShooterPlayerBase::OnHealthChange(float NawHealth)
{
	TextRenderComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"),NawHealth)));
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
