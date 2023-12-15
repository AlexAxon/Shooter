// Shooter game. All rights reserved!


#include "ShooterGameModeBase.h"
#include "PlayerControllerBase.h"
#include "ShooterPlayerBase.h"

AShooterGameModeBase::AShooterGameModeBase()
{
	DefaultPawnClass =  AShooterPlayerBase::StaticClass();
	PlayerControllerClass = APlayerControllerBase::StaticClass();
}