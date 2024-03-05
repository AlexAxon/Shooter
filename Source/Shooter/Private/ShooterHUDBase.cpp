// Shooter game. All rights reserved!


#include "ShooterHUDBase.h"
#include "Engine/Canvas.h"

void AShooterHUDBase::DrawHUD()
{
	Super::DrawHUD();
	DrawCross();
}

void AShooterHUDBase::DrawCross()
{
	int32 SizeX = Canvas->SizeX;
	int32 SizeY = Canvas->SizeY;
	float LineSize = 10.0f;
	float Thickness = 2.0f;
	TInterval<float> Center (SizeX * 0.5,SizeY * 0.5);
	FLinearColor LineColor = FLinearColor::Green;
	DrawLine(Center.Min - LineSize,Center.Max,Center.Min + LineSize,Center.Max,LineColor,Thickness);
	DrawLine(Center.Min,Center.Max - LineSize,Center.Min,Center.Max + LineSize,LineColor,Thickness);
}
