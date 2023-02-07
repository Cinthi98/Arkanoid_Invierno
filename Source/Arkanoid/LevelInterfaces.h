// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LevelInterfaces.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULevelInterfaces : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARKANOID_API ILevelInterfaces
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//Funciones virtuales puras para los niveles
	virtual void SetBrickLevel1() = 0;
	virtual void SetBrickLevel2() = 0;
	virtual void SetBrickLevel3() = 0;
	virtual void SetBrickLevel4() = 0;
	virtual void SetBrickLevel5() = 0;
	virtual void SetBrickLevel6() = 0;
	virtual void SetBrickLevel7() = 0;
	virtual void SetBrickLevel8() = 0;
	virtual void SetBrickLevel9() = 0;
	virtual void SetBrickLevel10() = 0;

};
