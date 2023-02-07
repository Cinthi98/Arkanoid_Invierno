// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "CapsuleDestroyBall.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ACapsuleDestroyBall : public ABasicCapsule
{
	GENERATED_BODY()

public:
	ACapsuleDestroyBall(); //Constructor

protected:
		virtual void BeginPlay() override;
	
};
