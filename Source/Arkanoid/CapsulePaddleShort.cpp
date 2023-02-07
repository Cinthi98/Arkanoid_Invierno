// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulePaddleShort.h"
#include "UObject/ConstructorHelpers.h"

ACapsulePaddleShort::ACapsulePaddleShort()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialPaddleShort(TEXT("Material'/Game/Assets/Materials/AntiAyuda/M_CapsulaAntiAyudaShortPaddle.M_CapsulaAntiAyudaShortPaddle'"));
	SM_BasicCapsule->SetMaterial(0, MaterialPaddleShort.Object);
}

void ACapsulePaddleShort::BeginPlay()
{
	Super::BeginPlay();

	CapsuleName = "Short";
}
