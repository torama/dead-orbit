// Fill out your copyright notice in the Description page of Project Settings.


#include "Planet.h"

// Sets default values
APlanet::APlanet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
	if (GEngine == nullptr) {
		return;
	}
	UWorld* world = this->GetWorld();
	if (world == nullptr) {
		return;
	}
	TerrainFaces.AddUninitialized(6);
	TArray<FVector> Directions = TArray<FVector>{
		FVector::UpVector,
		FVector::DownVector,
		FVector::LeftVector,
		FVector::RightVector,
		FVector::ForwardVector,
		FVector::BackwardVector
	};

	for (size_t i = 0; i < 6; i++)
	{
		TerrainFaces[i] = world->SpawnActor<AProceduralPlanet>(AProceduralPlanet::StaticClass(), this->GetActorLocation(), this->GetActorRotation());

	}

	for (size_t i = 0; i < TerrainFaces.Num(); i++)
	{
		if (TerrainFaces[i] != nullptr) {
			TerrainFaces[i]->CreateMesh(i, Directions[i], 100);
			TerrainFaces[i]->SetActorScale3D(this->GetActorScale3D());
		}

	}

	Super::BeginPlay();
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

