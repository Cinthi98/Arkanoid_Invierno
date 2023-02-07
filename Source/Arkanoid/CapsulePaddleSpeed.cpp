// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulePaddleSpeed.h"
#include "UObject/ConstructorHelpers.h"

ACapsulePaddleSpeed::ACapsulePaddleSpeed()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialPaddleSpeed(TEXT("Material'/Game/Assets/Materials/AntiAyuda/M_CapsulaAntiAyudaPaddleSpeed.M_CapsulaAntiAyudaPaddleSpeed'"));
	SM_BasicCapsule->SetMaterial(0, MaterialPaddleSpeed.Object);
}

void ACapsulePaddleSpeed::BeginPlay()
{
	Super::BeginPlay();

	CapsuleName = "Speed";
}
