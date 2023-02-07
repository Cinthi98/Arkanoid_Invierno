// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "TwoBall.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ATwoBall : public ABall
{
	GENERATED_BODY()
	
public:
	ATwoBall(); //Constructor

	virtual void LaunchTwoBall(); //Funcion de lanzamiento

	void DestroyTwoBall(); //Funcion de destructor

	
};
