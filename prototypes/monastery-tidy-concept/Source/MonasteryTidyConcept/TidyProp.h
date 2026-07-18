// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TidyProp.generated.h"

class AHomeSpot;

UCLASS()
class MONASTERYTIDYCONCEPT_API ATidyProp : public AActor
{
	GENERATED_BODY()

public:
	ATidyProp();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PropId = 0;

	UPROPERTY(BlueprintReadOnly)
	bool bIsHome = false;

	UPROPERTY(BlueprintReadOnly)
	AHomeSpot* AssignedHome = nullptr;

	void SetDragged(bool bDragging);
	void SnapToHome(AHomeSpot* Home);
	void LeaveHome();
	void ApplyColor(FLinearColor Color);
};
