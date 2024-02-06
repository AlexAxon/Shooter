// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTER_API UShooterHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShooterHealthComponent();
	float GetHealth() const { return Health; };
	UFUNCTION(BlueprintCallable)
	void TakeAnyDamage( AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable)
	bool IsDead(){return Health <= 0;}
	FOnDeath OnDeath;
	
private:
	float Health = 0.0f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,meta=(ClampMin = "0"),meta=(ClampMax = "500"))
	float MaxHealth = 100.0f;
};
