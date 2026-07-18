// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HomeSpot.generated.h"

UCLASS()
class MONASTERYTIDYCONCEPT_API AHomeSpot : public AActor
{
	GENERATED_BODY()

public:
	AHomeSpot();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* GhostMesh;

	/** Matching prop index (0..N-1). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HomeId = 0;

	void SetHighlight(bool bOn);
};
