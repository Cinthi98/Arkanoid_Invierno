// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthCapsule.h"


AHealthCapsule::AHealthCapsule()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Assets/Materials/Ayuda/M_CapsulaAyudaUnaVida.M_CapsulaAyudaUnaVida'"));
	SM_BasicCapsule->SetMaterial(0, MaterialCapsule.Object);
}

void AHealthCapsule::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 2;
}
