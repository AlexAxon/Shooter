// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemageActor.generated.h"

UCLASS()
class SHOOTER_API ADemageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADemageActor();
	
	// SceneComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USceneComponent* 	SceneComponent;
	
	// Radius
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius =  300.0f;
	
	// Color
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color = FColor::Purple;
	
	// Damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta=(ClampMin = "0.0"))
	float Damage = 10;
	
	// DoFullDamage
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DoFullDamage = false;

	//DamageType
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UDamageType> DamageType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
