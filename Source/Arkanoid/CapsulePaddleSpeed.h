// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "CapsulePaddleSpeed.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ACapsulePaddleSpeed : public ABasicCapsule
{
	GENERATED_BODY()

public:
	ACapsulePaddleSpeed(); //Constructor

protected:
	virtual void BeginPlay() override;
	
};
