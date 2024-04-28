// Shooter game. All rights reserved!


#include "WaeponComponent.h"

#include "ShooterWeaponBase.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UWaeponComponent::UWaeponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UWaeponComponent::StartFire()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->StartFire();
}

void UWaeponComponent::StopFire()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->StopFire();
}


// Called when the game starts
void UWaeponComponent::BeginPlay()
{
	Super::BeginPlay();
    Character = Cast<ACharacter>(GetOwner());
	SpawnWeapon();

	// ...
	
}

void UWaeponComponent::SpawnWeapon()
{
	CurrentWeapon =  GetWorld()->SpawnActor<AShooterWeaponBase>(MyShooterWeaponClass);
	
	if ( CurrentWeapon)
	{
		if (Character)
		{
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget,false);
			CurrentWeapon->AttachToComponent( (*Character).GetMesh(),AttachmentRules,"WeaponPoint");
			CurrentWeapon->SetOwner(GetOwner());
		}
	}
}

