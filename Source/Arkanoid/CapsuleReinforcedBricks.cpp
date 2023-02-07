// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsuleReinforcedBricks.h"

ACapsuleReinforcedBricks::ACapsuleReinforcedBricks()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Assets/Materials/Ayuda/M_CapsulaAntiAyudaBrickShield.M_CapsulaAntiAyudaBrickShield'"));
	SM_BasicCapsule->SetMaterial(0, MaterialCapsule.Object);
}

void ACapsuleReinforcedBricks::BeginPlay()
{
	Super::BeginPlay();

	NumCapsule = 6;
}
