// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Brick.h"
#include "Kismet/GameplayStatics.h"
#include "Bomba.generated.h"


class ProjectileMovement;
class UBoxComponent;
UCLASS()
class ARKANOID_API ABomba : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomba();



	UFUNCTION()
		void NotifyActorBeginOverlap(AActor* OtherActor); //Evento de colision

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UStaticMeshComponent* Projectile; //Malla del projectil

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UProjectileMovementComponent* Movement; //Movimiento de la bala

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UCapsuleComponent* Collision; //Colision de la bala


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UStaticMeshComponent* GetProjectile() const { return Projectile; } //Obtenemos la malla del projectil

	FORCEINLINE UProjectileMovementComponent* GetMovement() const { return Movement; } //Obtenemos el movimiento



	void TimerExplition();
	void DestroyBomba();
	FTimerHandle AcuaticaTimerHandle;

	//===================================================================================================
	//Puntero a la bomba con el nombre de instance
	UPROPERTY()
		ABomba* Instance;


};
