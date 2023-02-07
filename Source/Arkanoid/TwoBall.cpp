// Fill out your copyright notice in the Description page of Project Settings.


#include "TwoBall.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "ThreeBall.h"

ATwoBall::ATwoBall()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialTwoBall(TEXT("Material'/Game/Assets/Materials/M_CapsuleBall.M_CapsuleBall'"));
	SM_Ball->SetMaterial(0, MaterialTwoBall.Object);
}

void ATwoBall::LaunchTwoBall()
{
	Launch();
}

void ATwoBall::DestroyTwoBall()
{
	this->Destroy();
}

