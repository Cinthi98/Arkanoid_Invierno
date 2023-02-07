// Fill out your copyright notice in the Description page of Project Settings.


#include "ShotCapsule.h"



AShotCapsule::AShotCapsule()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Assets/Materials/Ayuda/M_CapsulaAyudaShotCapsule.M_CapsulaAyudaShotCapsule'"));
	SM_BasicCapsule->SetMaterial(0, MaterialCapsule.Object);
}

void AShotCapsule::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 3;
}
