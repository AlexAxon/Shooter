// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterProjectile.generated.h"



class USphereComponent;


UCLASS()
class SHOOTER_API AShooterProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShooterProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SphereRadius = 5.0f;

private:

	USphereComponent* SphereComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
