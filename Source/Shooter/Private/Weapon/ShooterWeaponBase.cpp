// Shooter game. All rights reserved!


#include "Weapon/ShooterWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"


// Sets default values
DEFINE_LOG_CATEGORY_STATIC(LogWeapon,All,All);
AShooterWeaponBase::AShooterWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SetRootComponent(WeaponMesh);

}

void AShooterWeaponBase::StartFire()
{
}


void AShooterWeaponBase::MakeShot()
{
}


void AShooterWeaponBase::StopFire()
{
}

// Called when the game starts or when spawned
void AShooterWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}


void AShooterWeaponBase::MakeDamage(FHitResult& HitResult)
{
	auto DamageActor = HitResult.GetActor();
	if (!DamageActor) return;
	DamageActor->TakeDamage(DamageAmount, FDamageEvent(), GetPlayerController(), this);
}

APlayerController* AShooterWeaponBase::GetPlayerController()
{
	const auto Player = Cast<ACharacter>(GetOwner());
	const auto Controller = Player->GetController<APlayerController>();
	return Controller;
}

bool AShooterWeaponBase::GetPlayerViewPoint(FRotator& ViewRotator, FVector& ViewLocation)
{
	const auto Controller = GetPlayerController();
	if (!Controller) return false;
	Controller->GetPlayerViewPoint(ViewLocation, ViewRotator);
	return true;
}

FVector AShooterWeaponBase::GetMagSocketLocation()
{
	return WeaponMesh->GetSocketLocation(MagSocket);
}

void AShooterWeaponBase::MakeHit(FHitResult& HitResult, FVector& TraceStart, FVector& TraceEnd)
{
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwner());
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility, QueryParams);
}

bool AShooterWeaponBase::GetTraceData(FVector& TraceStart, FVector& TraceEnd)
{
	FRotator ViewRotator;
	FVector ViewLocation;
	if (!GetPlayerViewPoint(ViewRotator, ViewLocation)) return false;
	FVector SocketLocation = GetMagSocketLocation();
	TraceStart = ViewLocation;
	FVector ShootDirection = ViewRotator.Vector();
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistanse;
	return true;
}
