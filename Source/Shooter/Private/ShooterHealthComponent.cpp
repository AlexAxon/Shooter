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


// Called when the game starts
void UShooterHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	// ...
	
}