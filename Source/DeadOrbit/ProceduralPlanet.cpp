#include "ProceduralPlanet.h"


AProceduralPlanet::AProceduralPlanet()
{
	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>("TerrainFace");
	RootComponent = ProcMesh;
	PlanetRadius = 30000;
}

void AProceduralPlanet::BeginPlay()
{
	Super::BeginPlay();

}

FVector AProceduralPlanet::CalculatePointOnPlanet(FVector PointOnPlanet)
{
	return PointOnPlanet * PlanetRadius * 2;
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

void AProceduralPlanet::CreateMesh(int32 Index, FVector LUp, int32 Res)
{
	AxisA = FVector(LUp.Y, LUp.Z, LUp.X);
	AxisB = FVector::CrossProduct(LUp, AxisA);
	TArray<FVector> Normals;
	Normals.Add(LUp);
	Normals.Add(LUp);
	Normals.Add(LUp);
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector> Vertices;
	Vertices.AddUninitialized(Res * Res);
	TArray<int32> Triangles;
	Triangles.AddUninitialized((Res - 1) * (Res - 1) * 6);
	int32 TriIndex = 0;
	for (size_t y = 0; y < Res; y++)
	{
		for (size_t x = 0; x < Res; x++)
		{
			int32 i = x + y * Res;
			FVector2D Percent = FVector2D(x, y) / (Res - 1);
			FVector PointOnUnitCube = LUp + (Percent.X - 0.5f) * 2 * AxisA + (Percent.Y - 0.5f) * 2 * AxisB;
			PointOnUnitCube.Normalize();
			Vertices[i] = CalculatePointOnPlanet(PointOnUnitCube);

			if (x != Res - 1 && y != Res - 1) {
				Triangles[TriIndex] = i + Res;
				Triangles[TriIndex + 1] = i + Res + 1;
				Triangles[TriIndex + 2] = i;

				Triangles[TriIndex + 3] = i + Res + 1;
				Triangles[TriIndex + 4] = i + 1;
				Triangles[TriIndex + 5] = i;

				TriIndex += 6;
			}
		}
	}
	ProcMesh->ClearMeshSection(Index);
	ProcMesh->CreateMeshSection(Index, Vertices, Triangles, Normals, UVs, TArray<FColor>(), Tangents, true);
	if (Material)
	{
		ProcMesh->SetMaterial(Index, Material);
	}
}

