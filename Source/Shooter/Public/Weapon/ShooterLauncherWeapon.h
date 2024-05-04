// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Weapon/ShooterWeaponBase.h"
#include "ShooterLauncherWeapon.generated.h"

/**
 * 
 */


class AShooterProjectile;

UCLASS()
class SHOOTER_API AShooterLauncherWeapon : public AShooterWeaponBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AShooterProjectile> ShooterProjectile;


private:



	virtual void StartFire() override;

	virtual void MakeShot() override;



};
