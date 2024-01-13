// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ShooterCharacterMovementCom.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UShooterCharacterMovementCom : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual float GetMaxSpeed() const override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="Movement",meta=(ClampMin = "1.5"),meta=(ClampMax = "10"))
	float RunModifier = 2.;
};
