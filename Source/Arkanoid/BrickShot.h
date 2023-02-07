// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrickShield_.h"
#include "BrickShot.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ABrickShot : public ABrickShield_
{
	GENERATED_BODY()
	
public:

	ABrickShot(); //Constructor

protected:

	UPROPERTY(EditAnywhere)
		class USoundBase* FireSound; // sonido de disparo

	void NotifyActorBeginOverlap(AActor* OtherActor); //Evento de colision

public:

	void DestroyBrickShot(); //Destruccion del ladrillo

	int HitBrick; //Contador de golpes

	float ShootTime; //Reinicio de disparo
	float TimeToSpawnShoot; //Tiempo para cada disparo
	FVector Projectile; //Angulo de lanzamiento de cada projectil

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
