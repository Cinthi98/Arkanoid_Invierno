// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCapsule.h"
#include "CapsuleReinforcedBricks.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ACapsuleReinforcedBricks : public ABasicCapsule
{
	GENERATED_BODY()

public:
	ACapsuleReinforcedBricks(); //Constructor

protected:
	virtual void BeginPlay() override;
	
};
