// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_PlayerController.generated.h"
class ABall;
class ATwoBall;
class AThreeBall;

/**
 * 
 */

UCLASS()
class ARKANOID_API APaddle_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APaddle_PlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override; //Funcion virtual al componente de entrada de configuración

protected:

	virtual void BeginPlay() override; //Funcion al iniciar el juego

protected:

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj; //Plantilla de la clase Ball

	UPROPERTY(EditAnywhere)
		TSubclassOf<AThreeBall> ThreeObj; //Plantilla de la clase ThreeBall

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATwoBall> TwoObj; //Plantilla de la clase TwoBall


	ABall* MyBall; //Puntero a Ball
	AThreeBall* ThreeBall1 = nullptr; //Puntero a TheeBall
	AThreeBall* ThreeBall2 = nullptr;
	AThreeBall* ThreeBall3 = nullptr;
	ATwoBall* TwoBall1 = nullptr; //Puntero a TwoBall
	ATwoBall* TwoBall2 = nullptr;
	FVector SpawnLocation = FVector(0.0f, 0.0f, 95.0f); //Vector de creacion
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f); //Vector de rotacion
	FActorSpawnParameters SpawnInfo0; //Parametros de spawn

	void MoveHorizontal(float _AxisValue); //Funcion de movilidad del paddle

public:

	virtual void Tick(float DeltaTime) override; //Tiempo de ejecucion 

	 void SpawnNewBall(); //Funcion de creacion de ball

	 void Launch(); //Funcion de lanzamiento de ball

	 void SpawnTwoBall(); //Funcion de creacion de twoball

	 void LaunchTwo(); //Funcion de lanzamiento de twoball

	 void SpawnThreeBall(); //Funcion de creacion de threeball

	 void LaunchThree(); //Funcion de lanzamiento de threeball

	 void DestroyBall(); //Funcion de destuccion de balls


//Cambios para el examen de invierno

	 //Funcion que suelta las bombas
	 void LaunchBombs();

	 UPROPERTY(EditAnywhere)
		 TSubclassOf<ABall> BombaObj; //Plantilla de la clase Bomba
	 class ABomba* MyBomba; //Puntero a Bomba
};

