// Shooter game. All rights reserved!


#include "Weapon/ShooterRifleWeapon.h"

void AShooterRifleWeapon::StartFire()
{
	MakeShot();
	GetWorldTimerManager().SetTimer(ShotTimerHandle, this, &AShooterRifleWeapon::MakeShot, TimebetweenShots, true);
}

void AShooterRifleWeapon::MakeShot()
{
	FVector TraceStart;
	FVector TraceEnd;
	GetTraceData(TraceStart, TraceEnd);
	if (!GetTraceData(TraceStart, TraceEnd)) return;
	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);
	if (HitResult.bBlockingHit)
	{
		DrawDebugLine(GetWorld(), GetMagSocketLocation(), HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0.0f, 3.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 22, FColor::Blue, false, 5.0f);
		MakeDamage(HitResult);
	}
	else
	{
		DrawDebugLine(GetWorld(), GetMagSocketLocation(), TraceEnd, FColor::Red, false, 3.0f, 0.0f, 3.0f);
	}
}

bool AShooterRifleWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd)
{
	FRotator ViewRotator;
	FVector ViewLocation;
	if (!GetPlayerViewPoint(ViewRotator, ViewLocation)) return false;
	FVector SocketLocation = GetMagSocketLocation();
	TraceStart = ViewLocation;
	const auto HalfRadius = FMath::DegreesToRadians(BulletSpread);
	FVector ShootDirection = FMath::VRandCone(ViewRotator.Vector(), HalfRadius);
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistanse;
	return true;
}

void AShooterRifleWeapon::StopFire()
{
	GetWorldTimerManager().ClearTimer(ShotTimerHandle);
}