// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreatorOfAntiCapsules.h"
#include "CapsulesAntiHelp.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ACapsulesAntiHelp : public ACreatorOfAntiCapsules
{
	GENERATED_BODY()

public:

	virtual ABasicCapsule* CreateCapsule(FString NameCapsule) override; //Funcion para la creacion de capsulas
	
};
