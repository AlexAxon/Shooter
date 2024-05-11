// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterProjectile.generated.h"



class USphereComponent;
class UProjectileMovementComponent;



UCLASS()
class SHOOTER_API AShooterProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShooterProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SphereRadius = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageAmount = 75.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)

	float DamageRadius = 200.0f;

	void SetDirection(FVector VectorDirection);

	FVector Direction;

	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:

	USphereComponent* SphereComponent;

	UProjectileMovementComponent* ProjectileMovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
