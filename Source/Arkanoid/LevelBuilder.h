// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LevelBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULevelBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARKANOID_API ILevelBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//Funciones virtuales puras para el constructor de los niveles
	virtual void BuildLevel1() = 0;
	virtual void BuildLevel2() = 0;
	virtual void BuildLevel3() = 0;
	virtual void BuildLevel4() = 0;
	virtual void BuildLevel5() = 0;
	virtual void BuildLevel6() = 0;
	virtual void BuildLevel7() = 0;
	virtual void BuildLevel8() = 0;
	virtual void BuildLevel9() = 0;
	virtual void BuildLevel10() = 0;

};
