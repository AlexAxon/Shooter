// Shooter game. All rights reserved!


#include "ShooterHealthComponent.h"

// Sets default values for this component's properties
UShooterHealthComponent::UShooterHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UShooterHealthComponent::TakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	Health = Health - Damage;
}


// Called when the game starts
void UShooterHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	AActor*  Player = GetOwner();
	// ...
	Player->OnTakeAnyDamage.AddDynamic(this, &UShooterHealthComponent::TakeAnyDamage);
	
}