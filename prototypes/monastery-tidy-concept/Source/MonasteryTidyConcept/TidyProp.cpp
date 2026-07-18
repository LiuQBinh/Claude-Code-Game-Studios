// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#include "TidyProp.h"
#include "HomeSpot.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"

ATidyProp::ATidyProp()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionObjectType(ECC_WorldDynamic);
	Mesh->SetCollisionResponseToAllChannels(ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	Mesh->SetSimulatePhysics(false);
	Mesh->SetRelativeScale3D(FVector(0.5f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (Cube.Succeeded())
	{
		Mesh->SetStaticMesh(Cube.Object);
	}
}

void ATidyProp::BeginPlay()
{
	Super::BeginPlay();
}

void ATidyProp::SetDragged(bool bDragging)
{
	Mesh->SetRelativeScale3D(bDragging ? FVector(0.58f) : FVector(0.5f));
}

void ATidyProp::SnapToHome(AHomeSpot* Home)
{
	if (!Home)
	{
		return;
	}
	AssignedHome = Home;
	bIsHome = true;
	SetActorLocation(Home->GetActorLocation());
	SetDragged(false);
}

void ATidyProp::LeaveHome()
{
	bIsHome = false;
	AssignedHome = nullptr;
}

void ATidyProp::ApplyColor(FLinearColor Color)
{
	UMaterialInterface* Base = Mesh->GetMaterial(0);
	if (!Base)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> DefaultMat(TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
		if (DefaultMat.Succeeded())
		{
			Base = DefaultMat.Object;
		}
	}
	if (Base)
	{
		UMaterialInstanceDynamic* MID = Mesh->CreateAndSetMaterialInstanceDynamicFromMaterial(0, Base);
		if (MID)
		{
			MID->SetVectorParameterValue(TEXT("Color"), Color);
			MID->SetVectorParameterValue(TEXT("BaseColor"), Color);
		}
	}
}
