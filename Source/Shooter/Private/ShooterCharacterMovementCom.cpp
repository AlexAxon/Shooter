// Shooter game. All rights reserved!

#include "ShooterPlayerBase.h"
#include "ShooterCharacterMovementCom.h"

float UShooterCharacterMovementCom::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();
	AShooterPlayerBase* Player = Cast<AShooterPlayerBase>(GetPawnOwner());
	return  Player && Player->IsRunning() ? MaxSpeed*RunModifier : MaxSpeed;
}
