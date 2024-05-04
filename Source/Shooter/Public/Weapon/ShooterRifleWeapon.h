// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Weapon/ShooterWeaponBase.h"
#include "ShooterRifleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AShooterRifleWeapon : public AShooterWeaponBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TimebetweenShots = 0.4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BulletSpread = 1.5f;


private:

	virtual void StopFire()	override;

	virtual void StartFire() override;
	
	virtual void MakeShot() override;

	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) override;

	FTimerHandle ShotTimerHandle;
};
