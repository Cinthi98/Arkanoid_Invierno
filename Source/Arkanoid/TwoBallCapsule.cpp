// Fill out your copyright notice in the Description page of Project Settings.


#include "TwoBallCapsule.h"



ATwoBallCapsule::ATwoBallCapsule()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Assets/Materials/Ayuda/M_CapsulaAyudaTwoBallCapsule.M_CapsulaAyudaTwoBallCapsule'"));
	SM_BasicCapsule->SetMaterial(0, MaterialCapsule.Object);
}

void ATwoBallCapsule::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 5;
}
