// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsuleAntiHealth.h"
#include "UObject/ConstructorHelpers.h"

ACapsuleAntiHealth::ACapsuleAntiHealth()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAntiHealth(TEXT("Material'/Game/Assets/Materials/AntiAyuda/M_CapsulaAntiAyudaVidaMenos.M_CapsulaAntiAyudaVidaMenos'"));
	SM_BasicCapsule->SetMaterial(0, MaterialAntiHealth.Object);
}


void ACapsuleAntiHealth::BeginPlay()
{
	Super::BeginPlay();

	CapsuleName = "AHealth";
}
