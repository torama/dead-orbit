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



	UPROPERTY()
	UProceduralMeshComponent* ProcMesh;

	void CreateMesh();
	void CreateQuad(TArray<FVector> Vertices, TArray<int32> Triangles, TArray<FVector2d> UVs, int32 Index);

public:
	AProceduralPlanet();

protected:
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
