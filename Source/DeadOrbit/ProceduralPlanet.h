// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralPlanet.generated.h"

UCLASS()
class DEADORBIT_API AProceduralPlanet : public AActor
{
	GENERATED_BODY()

public:
	AProceduralPlanet();
	int32 Resolution;
	FVector LocalUp;
	FVector AxisA;
	FVector AxisB;
	int32 PlanetRadius;

protected:
	virtual void BeginPlay() override;
	void CreateQuad(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector2d> UVs, int32 Index);

	UPROPERTY()
		UProceduralMeshComponent* ProcMesh;
	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material;

	FVector CalculatePointOnPlanet(FVector PointOnPlanet);

public:
	virtual void Tick(float DeltaTime) override;
	void CreateMesh(int32 Index, FVector LUp, int32 Res);
};
