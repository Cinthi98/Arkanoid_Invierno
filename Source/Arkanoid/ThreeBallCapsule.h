// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "Ball.h"
#include "ThreeBallCapsule.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AThreeBallCapsule : public ABasicCapsule
{
	GENERATED_BODY()

public:
	AThreeBallCapsule(); //Constructor

protected:

	virtual void BeginPlay() override; //funcion al inicio de juego

public:

	virtual void Tick(float DeltaTime) override; //funcion al tiempo de ejecucion


};
