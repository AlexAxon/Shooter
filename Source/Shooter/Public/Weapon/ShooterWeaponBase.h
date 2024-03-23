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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere,  BlueprintReadWrite)
	class USkeletalMeshComponent* WeaponMesh;

	void MakeShot();
};
