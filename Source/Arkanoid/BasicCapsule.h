// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicCapsule.generated.h"

UCLASS()
class ARKANOID_API ABasicCapsule : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicCapsule();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_BasicCapsule; //Malla del brick

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision; //Colision

	int NumCapsule; //Numero de las capsulas de ayuda

	FString CapsuleName; //Nombre de las capsulas de antiayuda

	UFUNCTION() //Campo de colision
		void ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE int GetIntCapsuleHelps() const { return NumCapsule; } //Obtenemos el numero de las capsulas de ayuda

	FORCEINLINE FString GetCapsuleNameAntiHelps() const { return CapsuleName; } //Obtenemos el nombre de las capsulas de antiayuda

	float x; //Direccion del movimiento
	float vc; //Velocidad del movimiento

};