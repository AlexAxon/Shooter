// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterWeaponBase.generated.h"

UCLASS()
class SHOOTER_API AShooterWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TimebetweenShots = 0.4;
	 
	AShooterWeaponBase();

	virtual void StartFire();

	virtual void StopFire();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TraceMaxDistanse = 2000.0f;

	FName MagSocket = "RifleMagSocket";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageAmount = 23.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BulletSpread = 1.5f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,  BlueprintReadWrite)
	class USkeletalMeshComponent* WeaponMesh;

	FTimerHandle ShotTimerHandle;
	
	void MakeShot();

	void MakeDamage(FHitResult& HitResult);

	APlayerController* GetPlayerController();
	
	bool GetPlayerViewPoint(FRotator& ViewRotator, FVector& ViewLocation);
	
	FVector GetMagSocketLocation();

	void MakeHit(FHitResult& HitResult, FVector& TraceStart, FVector& TraceEnd);

	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd);
};
