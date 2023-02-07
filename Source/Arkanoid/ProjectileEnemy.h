// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileEnemy.generated.h"

UCLASS()
class ARKANOID_API AProjectileEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UStaticMeshComponent* ProjectileEnemy; //Malla de la bala

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UProjectileMovementComponent* Movement; //Movimiento de la bala

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UCapsuleComponent* Collision; //Colision

	UFUNCTION()
		void NotifyActorBeginOverlap(AActor* OtherActor); //Evento de colision

	FORCEINLINE UStaticMeshComponent* GetProjectile() const { return ProjectileEnemy; } //Obtenemos la malla

	FORCEINLINE UProjectileMovementComponent* GetMovement() const { return Movement; } //Obtenemos el movimiento

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
