// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulePaddleStatic.h"
#include "UObject/ConstructorHelpers.h"

ACapsulePaddleStatic::ACapsulePaddleStatic()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialPaddleStatic(TEXT("Material'/Game/Assets/Materials/AntiAyuda/M_CapsulaAntiAyudaStaticPaddle.M_CapsulaAntiAyudaStaticPaddle'"));
	SM_BasicCapsule->SetMaterial(0, MaterialPaddleStatic.Object);
}

void ACapsulePaddleStatic::BeginPlay()
{
	Super::BeginPlay();

	CapsuleName = "Static";
}
