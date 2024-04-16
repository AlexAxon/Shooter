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
	AShooterWeaponBase();
	void Fire();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TraceMaxDistanse = 2000.0f;

	FName MagSocket = "RifleMagSocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float DamageAmount = 23.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,  BlueprintReadWrite)
	class USkeletalMeshComponent* WeaponMesh;

	void MakeShot();

	void MakeDamage(FHitResult& HitResult);

	APlayerController* GetPlayerController();
	
	bool GetPlayerViewPoint(FRotator& ViewRotator, FVector& ViewLocation);
	
	FVector GetMagSocketLocation();

	void MakeHit(FHitResult& HitResult, FVector& TraceStart, FVector& TraceEnd);

	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd);
};
