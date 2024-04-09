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
	const auto Player = Cast<ACharacter>(GetOwner());

	const auto Controller = Player->GetController<APlayerController>();
	FRotator ViewRotator;
	FVector ViewLocation;
	Controller->GetPlayerViewPoint(ViewLocation, ViewRotator);

	FTransform SocketTransform = WeaponMesh->GetSocketTransform("RifleMagSocket");
	FVector TraceStart = ViewLocation;
	FVector ShootDirection = ViewRotator.Vector();
	FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDistanse;
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwner());
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility, QueryParams);
	if (HitResult.bBlockingHit)
	{
		DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0.0f, 3.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 22, FColor::Blue, false, 5.0f);
	}
	else
	{
		DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), TraceEnd, FColor::Red, false, 3.0f, 0.0f, 3.0f);
	}
}