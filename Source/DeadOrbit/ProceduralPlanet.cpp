#include "ProceduralPlanet.h"


AProceduralPlanet::AProceduralPlanet()
{
	ProcMesh = CreateEditorOnlyDefaultSubobject<UProceduralMeshComponent>("ProceduralPlanet");
	RootComponent = ProcMesh;
}

void AProceduralPlanet::BeginPlay()
{
	Super::BeginPlay();
	CreateMesh();

}

void AProceduralPlanet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AProceduralPlanet::CreateQuad(TArray<FVector> Vertices, TArray<int32>Triangles, TArray<FVector2D> UVs, int32 Index) {
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;

	ProcMesh->CreateMeshSection(Index, Vertices, Triangles, Normals, UVs, TArray<FColor>(), Tangents, true);
	if (Material)
	{
		ProcMesh->SetMaterial(Index, Material);
	}

}

void AProceduralPlanet::CreateMesh()
{

	// Top
	CreateQuad(TArray<FVector> {
		FVector(0, 0, 0),
			FVector(0, 100, 0),
			FVector(100, 100, 0),
			FVector(100, 0, 0)
	}, TArray<int32> {0, 1, 2, 0, 2, 3 },
			TArray<FVector2D> {
			FVector2D(0, 0),
				FVector2D(0, 1),
				FVector2D(1, 1),
				FVector2D(1, 0)
		},
			0);

	// Bottom
	CreateQuad(TArray<FVector> {
		FVector(0, 0, -100),
			FVector(0, 100, -100),
			FVector(100, 100, -100),
			FVector(100, 0, -100)
	}, TArray<int32> {2, 1, 0, 3, 2, 0 },
			TArray<FVector2D> {
			FVector2D(1, 0),
				FVector2D(1, 1),
				FVector2D(0, 1),
				FVector2D(0, 0),
		},
			1);

	// Front
	CreateQuad(TArray<FVector> {
		FVector(0, 100, 0),
			FVector(0, 100, -100),
			FVector(100, 100, -100),
			FVector(100, 100, 0)
	}, TArray<int32> {0, 1, 2, 0, 2, 3 },
			TArray<FVector2D> {
			FVector2D(0, 0),
				FVector2D(0, 1),
				FVector2D(1, 1),
				FVector2D(1, 0)
		},
			2);

	// Back
	CreateQuad(TArray<FVector> {
		FVector(0, 0, 0),
			FVector(0, 0, -100),
			FVector(100, 0, -100),
			FVector(100, 0, 0)
	}, TArray<int32> {2, 1, 0, 3, 2, 0 },
			TArray<FVector2D> {
			FVector2D(1, 0),
				FVector2D(1, 1),
				FVector2D(0, 1),
				FVector2D(0, 0),
		},
			3);

	// Left
	CreateQuad(TArray<FVector> {
		FVector(0, 0, -100),
			FVector(0, 100, -100),
			FVector(0, 100, 0),
			FVector(0, 0, 0)
	}, TArray<int32> {0, 1, 2, 0, 2, 3 },
			TArray<FVector2D> {
			FVector2D(0, 1),
				FVector2D(1, 1),
				FVector2D(1, 0),
				FVector2D(0, 0),
		},
			4);

	// Right
	CreateQuad(TArray<FVector> {
		FVector(100, 0, -100),
			FVector(100, 100, -100),
			FVector(100, 100, 0),
			FVector(100, 0, 0)
	}, TArray<int32> {2, 1, 0, 3, 2, 0 },
			TArray<FVector2D> {
				FVector2D(1, 1),
				FVector2D(0, 1),
				FVector2D(0, 0),
					FVector2D(1, 0),
		},
			5);
}

