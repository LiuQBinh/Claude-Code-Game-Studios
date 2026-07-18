// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TidyPrototypeGameMode.generated.h"

UCLASS()
class MONASTERYTIDYCONCEPT_API ATidyPrototypeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATidyPrototypeGameMode();

	virtual void BeginPlay() override;

protected:
	void SpawnPrototypeScene();
};
