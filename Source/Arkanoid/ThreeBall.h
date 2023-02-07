// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "ThreeBall.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AThreeBall : public ABall
{
	GENERATED_BODY()

public:
	AThreeBall(); //Constructor

	virtual void LaunchThreeBall(); //Funcion de lanzamiento

	void DestroyThree(); //Funcion de destructor

};
