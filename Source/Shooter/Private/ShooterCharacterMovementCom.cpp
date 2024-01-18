// Shooter game. All rights reserved!

#include "ShooterCharacterMovementCom.h"
#include "ShooterPlayerBase.h"


float UShooterCharacterMovementCom::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();
	AShooterPlayerBase* Player = Cast<AShooterPlayerBase>(GetPawnOwner());
	return  Player && Player->IsRunning() ? MaxSpeed*RunModifier : MaxSpeed;
}
