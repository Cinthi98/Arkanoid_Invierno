// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatorOfAntiCapsules.h"

// Sets default values
ACreatorOfAntiCapsules::ACreatorOfAntiCapsules()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACreatorOfAntiCapsules::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreatorOfAntiCapsules::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABasicCapsule* ACreatorOfAntiCapsules::OrdenCapsule(FString Category)
{
	ABasicCapsule* Capsules = CreateCapsule(Category);
	return Capsules;
}
