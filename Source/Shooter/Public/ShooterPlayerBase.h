// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterPlayerBase.generated.h"

UCLASS()
class SHOOTER_API AShooterPlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterPlayerBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArmComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	bool IsRunning();


private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void StarRunning();
	void StopRunning();
	bool WantRunning = false;
	bool IsMoveForward = false;
	
	/*
	void TurnTop(float Amount);
	void TurnAround(float Amount);
	*/
};
