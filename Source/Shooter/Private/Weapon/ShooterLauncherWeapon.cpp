// Shooter game. All rights reserved!


#include "Weapon/ShooterLauncherWeapon.h"
#include "Shooter/Public/Weapon/ShooterProjectile.h"
#include "Kismet/GameplayStatics.h"


void AShooterLauncherWeapon::StartFire()
{
	MakeShot();
}


void AShooterLauncherWeapon::MakeShot()
{
	FVector TraceStart;
	FVector TraceEnd;
	GetTraceData(TraceStart, TraceEnd);
	if (!GetTraceData(TraceStart, TraceEnd)) return;
	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);
	FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;  
	FVector Direction = (EndPoint - GetMagSocketLocation()).GetSafeNormal()

	FTransform SpawnTransform = FTransform(FRotator::ZeroRotator, GetMagSocketLocation());
	AShooterProjectile* Projectile = GetWorld()->SpawnActorDeferred<AShooterProjectile>(ShooterProjectile, SpawnTransform);
	UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);

}
