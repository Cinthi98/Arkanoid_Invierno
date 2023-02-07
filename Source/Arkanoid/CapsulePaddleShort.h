// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "CapsulePaddleShort.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ACapsulePaddleShort : public ABasicCapsule
{
	GENERATED_BODY()

public:
	ACapsulePaddleShort(); //Constructor

protected:
	virtual void BeginPlay() override;
	
};
