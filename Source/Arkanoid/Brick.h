// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicCapsule.h"
#include "Brick.generated.h"
UCLASS()
class ARKANOID_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

	void ContBricksLevel(int _Cont); //Contador de ladrillos de nivel 

	void RestoreLevel(int Restore); //Restablecimiento de los bricks del nivel

	int GetBricksLevel(); // Obtenemos los bricks del nivel 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* SM_Brick; //Ladrillo

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Collision;  //Caja Colision

	UPROPERTY(EditAnywhere)
		class USoundBase* BounceSound; // sonido de rebote

	UPROPERTY()
		class UMaterialInstanceDynamic* MaterialInstance; //Instancia de un material

	UPROPERTY()
		class UMaterialInterface* _Dynamic; //Dinamismo del color

	UFUNCTION(BlueprintCallable)
		void ChangeColor(); //Cambio de color

	float SpeedModifierOnBounce = 1.02f; //Modificador de velocidad

	UFUNCTION() //Entra en la caja
		virtual void NotifyActorBeginOverlap(AActor* OtherActor) override; //Funcion virtual pura de la colision

	void CreateCapsule(FVector Location); //Funcion virtual pura de la creacion de las capsulas

private:

	bool HabilitadoCreacionCapsulas; //Booleano para la creacion de capsulas

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DestroyBrick(); //Destruccion del brick

	virtual ABasicCapsule* CreateCapsule(int NumCapsule, FVector Location) PURE_VIRTUAL(ABrick::CreateCapsule, return nullptr;); //Funcion virtual pura a basic capsule

	ABasicCapsule* OrdenCapsule(int NumCategory, FVector Spawn); //Funcion para la creacion de las capsulas

};
