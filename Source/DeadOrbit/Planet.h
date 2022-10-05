// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralPlanet.h"
#include "Planet.generated.h"

UCLASS()
class DEADORBIT_API APlanet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TArray<AProceduralPlanet*> TerrainFaces;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
