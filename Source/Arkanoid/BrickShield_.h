// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BrickShield_.generated.h"

UCLASS()
class ARKANOID_API ABrickShield_ : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrickShield_();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* SM_BrickShield; //Ladrillo de disparo

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Collision; //Colision

	UPROPERTY(EditAnywhere)
		class USoundBase* BounceSound; // sonido de rebote

	UPROPERTY()
		class UMaterialInstanceDynamic* MaterialInstance; //Instancia de un material

	UPROPERTY()
		class UMaterialInterface* _Dynamic; //Dinamismo del color

	UFUNCTION() //Evento de colision
		virtual void NotifyActorBeginOverlap(AActor* OtherActor);

	float SpeedModifierOnBounce = 1.2f; //Modificador de velocidad

	void ChangeColor(); //Cambio de color

	FTimerHandle UnusedHandle; //Temporizador de operatividad

public:
	void DestroyBrick(); //Destruccion del ladrillo

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
