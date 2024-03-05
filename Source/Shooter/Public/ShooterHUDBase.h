// Shooter game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShooterHUDBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AShooterHUDBase : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;

private:
	void DrawCross();
};
