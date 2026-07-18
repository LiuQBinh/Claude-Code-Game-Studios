// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#include "HomeSpot.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AHomeSpot::AHomeSpot()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	GhostMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GhostMesh"));
	GhostMesh->SetupAttachment(Root);
	GhostMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GhostMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	GhostMesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	GhostMesh->SetGenerateOverlapEvents(true);
	GhostMesh->SetRelativeScale3D(FVector(0.55f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (Cube.Succeeded())
	{
		GhostMesh->SetStaticMesh(Cube.Object);
	}
}

void AHomeSpot::SetHighlight(bool bOn)
{
	GhostMesh->SetVisibility(true);
	GhostMesh->SetScalarParameterValueOnMaterials(TEXT("Opacity"), bOn ? 0.55f : 0.25f);
}
