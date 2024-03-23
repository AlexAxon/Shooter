// Shooter game. All rights reserved!


#include "Weapon/ShooterWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
DEFINE_LOG_CATEGORY_STATIC(LogWeapon,All,All);
AShooterWeaponBase::AShooterWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SetRootComponent(WeaponMesh);

}

void AShooterWeaponBase::Fire()
{
	UE_LOG(LogWeapon,Display,TEXT("Fire"));
	MakeShot();
}

// Called when the game starts or when spawned
void AShooterWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShooterWeaponBase::MakeShot()
{
	FTransform SocketTransform = WeaponMesh->GetSocketTransform("RifleMagSocket");
	FVector TraceStart = SocketTransform.GetLocation();
	FVector ShootDirection = SocketTransform.GetRotation().GetForwardVector();
	FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDistanse;
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 3.0f, 0.0f, 3.0f);
	if (HitResult.bBlockingHit)
	{
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 22, FColor::Blue, false, 5.0f);
	}

}