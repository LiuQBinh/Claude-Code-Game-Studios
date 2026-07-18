// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#include "TidyPlayerController.h"
#include "TidyProp.h"
#include "HomeSpot.h"
#include "TidyHUD.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"

ATidyPlayerController::ATidyPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	PrimaryActorTick.bCanEverTick = true;
}

void ATidyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(Mode);
}

void ATidyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("LeftMouseButton", IE_Pressed, this, &ATidyPlayerController::OnLmbPressed);
	InputComponent->BindAction("LeftMouseButton", IE_Released, this, &ATidyPlayerController::OnLmbReleased);

	// Fallback bindings if project action map is empty
	InputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &ATidyPlayerController::OnLmbPressed);
	InputComponent->BindKey(EKeys::LeftMouseButton, IE_Released, this, &ATidyPlayerController::OnLmbReleased);
}

void ATidyPlayerController::RegisterProps(const TArray<ATidyProp*>& InProps, const TArray<AHomeSpot*>& InHomes)
{
	Props = InProps;
	Homes = InHomes;
	RecalcPurity();
}

void ATidyPlayerController::RecalcPurity()
{
	int32 HomeCount = 0;
	for (ATidyProp* P : Props)
	{
		if (P && P->bIsHome)
		{
			++HomeCount;
		}
	}

	const int32 Total = Props.Num();
	const float Purity = Total > 0 ? static_cast<float>(HomeCount) / static_cast<float>(Total) : 0.f;

	if (ATidyHUD* H = Cast<ATidyHUD>(GetHUD()))
	{
		H->PropsHome = HomeCount;
		H->PropsTotal = Total;
		H->Purity01 = Purity;
		if (Purity >= 0.999f)
		{
			H->bRevealed = true;
			if (!bWasRevealed)
			{
				bWasRevealed = true;
				RevealAlpha = 0.01f;
			}
		}
	}
}

FVector ATidyPlayerController::GetCursorWorldOnPlayPlane() const
{
	FVector WorldOrigin, WorldDir;
	if (!DeprojectMousePositionToWorld(WorldOrigin, WorldDir))
	{
		return FVector::ZeroVector;
	}

	// Intersect ray with plane Y = PlayPlaneY (side-view / cutaway)
	if (FMath::Abs(WorldDir.Y) < KINDA_SMALL_NUMBER)
	{
		return WorldOrigin;
	}
	const float T = (PlayPlaneY - WorldOrigin.Y) / WorldDir.Y;
	return WorldOrigin + WorldDir * T;
}

ATidyProp* ATidyPlayerController::TracePropUnderCursor() const
{
	FVector WorldOrigin, WorldDir;
	if (!DeprojectMousePositionToWorld(WorldOrigin, WorldDir))
	{
		return nullptr;
	}

	const FVector End = WorldOrigin + WorldDir * 100000.f;
	FHitResult Hit;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(TidyTrace), true);
	if (GetWorld()->LineTraceSingleByChannel(Hit, WorldOrigin, End, ECC_Visibility, Params))
	{
		return Cast<ATidyProp>(Hit.GetActor());
	}
	return nullptr;
}

AHomeSpot* ATidyPlayerController::FindNearestMatchingHome(ATidyProp* Prop, float MaxDist) const
{
	if (!Prop)
	{
		return nullptr;
	}
	AHomeSpot* Best = nullptr;
	float BestDistSq = MaxDist * MaxDist;
	for (AHomeSpot* Home : Homes)
	{
		if (!Home || Home->HomeId != Prop->PropId)
		{
			continue;
		}
		const float DistSq = FVector::DistSquared(Prop->GetActorLocation(), Home->GetActorLocation());
		if (DistSq < BestDistSq)
		{
			BestDistSq = DistSq;
			Best = Home;
		}
	}
	return Best;
}

void ATidyPlayerController::OnLmbPressed()
{
	ATidyProp* Hit = TracePropUnderCursor();
	if (!Hit)
	{
		return;
	}
	if (Hit->bIsHome)
	{
		Hit->LeaveHome();
		RecalcPurity();
	}
	DraggedProp = Hit;
	DraggedProp->SetDragged(true);
	PlayPlaneY = Hit->GetActorLocation().Y;
}

void ATidyPlayerController::OnLmbReleased()
{
	if (!DraggedProp)
	{
		return;
	}

	AHomeSpot* Home = FindNearestMatchingHome(DraggedProp, 120.f);
	if (Home)
	{
		DraggedProp->SnapToHome(Home);
	}
	else
	{
		DraggedProp->SetDragged(false);
	}

	DraggedProp = nullptr;
	RecalcPurity();
}

void ATidyPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (DraggedProp)
	{
		const FVector Target = GetCursorWorldOnPlayPlane();
		FVector Loc = Target;
		Loc.Y = PlayPlaneY;
		DraggedProp->SetActorLocation(Loc);

		for (AHomeSpot* Home : Homes)
		{
			if (Home)
			{
				const bool bMatch = Home->HomeId == DraggedProp->PropId
					&& FVector::Dist(DraggedProp->GetActorLocation(), Home->GetActorLocation()) < 120.f;
				Home->SetHighlight(bMatch);
			}
		}
	}

	if (bWasRevealed && RevealAlpha < 1.f)
	{
		RevealAlpha = FMath::Min(1.f, RevealAlpha + DeltaSeconds * 0.6f);
		if (ATidyHUD* H = Cast<ATidyHUD>(GetHUD()))
		{
			H->RevealAlpha = RevealAlpha;
			H->bRevealed = true;
		}
	}
}
