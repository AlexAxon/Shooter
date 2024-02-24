// Shooter game. All rights reserved!


#include "Weapon/ShooterWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AShooterWeaponBase::AShooterWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SetRootComponent(WeaponMesh);

}

// Called when the game starts or when spawned
void AShooterWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}
