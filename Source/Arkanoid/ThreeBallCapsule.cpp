// Fill out your copyright notice in the Description page of Project Settings.


#include "ThreeBallCapsule.h"


AThreeBallCapsule::AThreeBallCapsule()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Assets/Materials/Ayuda/M_CapsulaAyudaThreeBallCapsule.M_CapsulaAyudaThreeBallCapsule'"));
	SM_BasicCapsule->SetMaterial(0, MaterialCapsule.Object);
}

void AThreeBallCapsule::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 4;

}

void AThreeBallCapsule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

