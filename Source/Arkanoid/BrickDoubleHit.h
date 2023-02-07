// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrickShield_.h"
#include "BrickDoubleHit.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ABrickDoubleHit : public ABrickShield_
{
	GENERATED_BODY()

public:
	ABrickDoubleHit(); //Constructor

protected:

	void NotifyActorBeginOverlap(AActor* OtherActor); //Campo de colision

public:

	void DestroyBrickDoubleHit(); //Destruccion del ladrillo

	int ContHit; //Contador de golpes

	
};
