// Shooter game. All rights reserved!


#include "ShooterGameModeBase.h"
#include "PlayerControllerBase.h"
#include "ShooterPlayerBase.h"
#include "ShooterHUDBase.h"

AShooterGameModeBase::AShooterGameModeBase()
{
	DefaultPawnClass =  AShooterPlayerBase::StaticClass();
	PlayerControllerClass = APlayerControllerBase::StaticClass();
	HUDClass = AShooterHUDBase::StaticClass();
}