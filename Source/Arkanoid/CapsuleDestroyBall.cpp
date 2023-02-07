// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsuleDestroyBall.h"
#include "UObject/ConstructorHelpers.h"

ACapsuleDestroyBall::ACapsuleDestroyBall()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialDestroyBall(TEXT("Material'/Game/Assets/Materials/AntiAyuda/M_CapsulaAntiAyudaDestroyBall.M_CapsulaAntiAyudaDestroyBall'"));
	SM_BasicCapsule->SetMaterial(0, MaterialDestroyBall.Object);
}

void ACapsuleDestroyBall::BeginPlay()
{
	Super::BeginPlay();

	CapsuleName = "Destroy";
}
