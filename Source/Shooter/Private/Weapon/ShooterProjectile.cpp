// Shooter game. All rights reserved!


#include "Weapon/ShooterProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AShooterProjectile::AShooterProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	ProjectileMovementComponent->InitialSpeed = 2000.0f;
	SetRootComponent(SphereComponent);
	SphereComponent->InitSphereRadius(SphereRadius);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

void AShooterProjectile::SetDirection(FVector VectorDirection)
{
	Direction = VectorDirection;

}

void AShooterProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

// Called when the game starts or when spawned
void AShooterProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMovementComponent->Velocity = Direction * ProjectileMovementComponent->InitialSpeed;
	SetLifeSpan(5.0f);
	SphereComponent->OnComponentHit.AddDynamic(this, &AShooterProjectile::OnProjectileHit);
}

