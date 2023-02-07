// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Brick.h"
#include "HelpCapsules.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AHelpCapsules : public ABrick
{
	GENERATED_BODY()


public:

	virtual ABasicCapsule* CreateCapsule(int NumCapsule, FVector Location) override; //Funcion para la creacion de las capsulas de ayuda
};
