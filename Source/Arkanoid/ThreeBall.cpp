// Fill out your copyright notice in the Description page of Project Settings.


#include "ThreeBall.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "TwoBall.h"

AThreeBall::AThreeBall()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialThreeBall(TEXT("Material'/Game/Assets/Materials/M_CapsuleBall.M_CapsuleBall'"));
	SM_Ball->SetMaterial(0, MaterialThreeBall.Object);

}

void AThreeBall::LaunchThreeBall()
{
	Launch();
}

void AThreeBall::DestroyThree()
{
	this->Destroy();
}


