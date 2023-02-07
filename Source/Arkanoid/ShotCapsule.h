// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "ShotCapsule.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AShotCapsule : public ABasicCapsule
{
	GENERATED_BODY()
	
public:
	AShotCapsule(); //Constructor

protected:

	virtual void BeginPlay() override;
};
