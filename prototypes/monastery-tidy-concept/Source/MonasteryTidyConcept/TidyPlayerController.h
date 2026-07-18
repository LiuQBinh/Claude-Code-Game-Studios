// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TidyPlayerController.generated.h"

class ATidyProp;
class AHomeSpot;
class ATidyHUD;

UCLASS()
class MONASTERYTIDYCONCEPT_API ATidyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATidyPlayerController();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;

	void RegisterProps(const TArray<ATidyProp*>& InProps, const TArray<AHomeSpot*>& InHomes);
	void RecalcPurity();

protected:
	void OnLmbPressed();
	void OnLmbReleased();

	FVector GetCursorWorldOnPlayPlane() const;
	ATidyProp* TracePropUnderCursor() const;
	AHomeSpot* FindNearestMatchingHome(ATidyProp* Prop, float MaxDist) const;

	UPROPERTY()
	ATidyProp* DraggedProp = nullptr;

	UPROPERTY()
	TArray<ATidyProp*> Props;

	UPROPERTY()
	TArray<AHomeSpot*> Homes;

	/** Side-view play plane: camera looks along +Y, move on XZ. */
	float PlayPlaneY = 0.f;

	bool bWasRevealed = false;
	float RevealAlpha = 0.f;
};
