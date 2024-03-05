// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "ShooterWeaponBase.h"
#include "Components/ActorComponent.h"
#include "WaeponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTER_API UWaeponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWaeponComponent();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AShooterWeaponBase> MyShooterWeaponClass;

	void Fire();

	
	AShooterWeaponBase* CurrentWeapon;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
private:
	ACharacter* Character;
	
	void SpawnWeapon();
	
};
