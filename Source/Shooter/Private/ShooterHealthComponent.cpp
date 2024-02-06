// Shooter game. All rights reserved!


#include "ShooterHealthComponent.h"
#include "Dev/IceDamageType.h"
#include "Dev/FireDamageType.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealth,All,All)
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
	if (IsDead() || Damage <= 0) return;
	Health = FMath::Clamp(Health - Damage,0,MaxHealth);
	if (IsDead()) OnDeath.Broadcast();
	if (DamageType)
	{
		if (DamageType->IsA<UIceDamageType>())
		{
			UE_LOG(LogHealth,Display, TEXT("COLD!"));
		}
		else if (DamageType->IsA<UFireDamageType>())
		{
			UE_LOG(LogHealth,Display, TEXT("HOT!"));
		}
	}
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