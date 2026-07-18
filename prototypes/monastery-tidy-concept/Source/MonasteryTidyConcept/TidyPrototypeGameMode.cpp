// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#include "TidyPrototypeGameMode.h"
#include "TidyPlayerController.h"
#include "TidyHUD.h"
#include "TidyProp.h"
#include "HomeSpot.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpectatorPawn.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ATidyPrototypeGameMode::ATidyPrototypeGameMode()
{
	PlayerControllerClass = ATidyPlayerController::StaticClass();
	HUDClass = ATidyHUD::StaticClass();
	DefaultPawnClass = ASpectatorPawn::StaticClass();
}

void ATidyPrototypeGameMode::BeginPlay()
{
	Super::BeginPlay();
	SpawnPrototypeScene();
}

void ATidyPrototypeGameMode::SpawnPrototypeScene()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// Orthographic side-view camera looking along +Y at the XZ play plane
	FActorSpawnParameters CamParams;
	CamParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ACameraActor* Cam = World->SpawnActor<ACameraActor>(
		ACameraActor::StaticClass(),
		FVector(0.f, -800.f, 120.f),
		FRotator(0.f, 90.f, 0.f),
		CamParams);

	if (Cam)
	{
		if (UCameraComponent* C = Cam->GetCameraComponent())
		{
			C->ProjectionMode = ECameraProjectionMode::Orthographic;
			C->OrthoWidth = 1200.f;
			C->bConstrainAspectRatio = false;
		}
	}

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0))
	{
		PC->SetViewTargetWithBlend(Cam, 0.f);
		PC->bAutoManageActiveCameraTarget = false;
	}

	// Paper-ish palette (approx) for colored boxes
	const TArray<FLinearColor> Colors = {
		FLinearColor(0.91f, 0.66f, 0.15f), // saffron
		FLinearColor(0.76f, 0.27f, 0.05f), // terracotta
		FLinearColor(0.24f, 0.42f, 0.31f), // forest
		FLinearColor(0.94f, 0.90f, 0.83f), // cream
		FLinearColor(0.29f, 0.22f, 0.16f), // brown
	};

	// Home positions (tidy shelf row)
	const TArray<FVector> HomeLocs = {
		FVector(-350.f, 0.f, 40.f),
		FVector(-175.f, 0.f, 40.f),
		FVector(0.f, 0.f, 40.f),
		FVector(175.f, 0.f, 40.f),
		FVector(350.f, 0.f, 40.f),
	};

	// Messy starting positions
	const TArray<FVector> MessyLocs = {
		FVector(-280.f, 0.f, -80.f),
		FVector(90.f, 0.f, -40.f),
		FVector(-40.f, 0.f, 160.f),
		FVector(300.f, 0.f, -120.f),
		FVector(-150.f, 0.f, 90.f),
	};

	TArray<ATidyProp*> Props;
	TArray<AHomeSpot*> Homes;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	const int32 Count = 5;
	for (int32 i = 0; i < Count; ++i)
	{
		AHomeSpot* Home = World->SpawnActor<AHomeSpot>(AHomeSpot::StaticClass(), HomeLocs[i], FRotator::ZeroRotator, SpawnParams);
		if (Home)
		{
			Home->HomeId = i;
			Homes.Add(Home);
		}

		ATidyProp* Prop = World->SpawnActor<ATidyProp>(ATidyProp::StaticClass(), MessyLocs[i], FRotator::ZeroRotator, SpawnParams);
		if (Prop)
		{
			Prop->PropId = i;
			Prop->ApplyColor(Colors[i % Colors.Num()]);
			Props.Add(Prop);
		}
	}

	if (ATidyPlayerController* TPC = Cast<ATidyPlayerController>(UGameplayStatics::GetPlayerController(World, 0)))
	{
		TPC->RegisterProps(Props, Homes);
	}
}
