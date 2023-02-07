// Fill out your copyright notice in the Description page of Project Settings.


#include "ElongationCapsule.h"



AElongationCapsule::AElongationCapsule()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Assets/Materials/Ayuda/M_CapsulaAyudaElongationCapsule.M_CapsulaAyudaElongationCapsule'"));
	SM_BasicCapsule->SetMaterial(0, MaterialCapsule.Object);
}

void AElongationCapsule::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 1;
}
