// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TidyHUD.generated.h"

UCLASS()
class MONASTERYTIDYCONCEPT_API ATidyHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

	UPROPERTY()
	float Purity01 = 0.f;

	UPROPERTY()
	int32 PropsHome = 0;

	UPROPERTY()
	int32 PropsTotal = 0;

	UPROPERTY()
	bool bRevealed = false;

	UPROPERTY()
	float RevealAlpha = 0.f;
};
