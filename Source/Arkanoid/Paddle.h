// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"
 
UCLASS()
class ARKANOID_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION() //Notificacion de la colision
		void OnOverlapBeginPaddle(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void NormalScale(); //Paddle de caracteristicas base
	void NormalVelocity(); //Paddle de caracteristicas base
	void NormalFire(); //Paddle de caracteristicas base
	void DestroyReinforced(); //Paddle de caracteristicas base

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* SM_Paddle; //Malla del paddle

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* PaddleCollision; //Colision

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UFloatingPawnMovement* FloatingMovement; //Movimiento

	UPROPERTY(EditAnywhere)
		class USoundBase* BounceSound; // sonido de rebote

	UPROPERTY(EditAnywhere)
		class USoundBase* FireSound; // sonido de disparo

	UPROPERTY()
		class ABrick* Brick; //Puntero a Brick

	UPROPERTY()
		class ALevelBricks* LevelBricks; //Puntero a level bricks

	FVector Location = this->GetActorLocation(); //Obtenemos la direccion del actor

	int32 GameOver; //Cuando las vidas del jugador lleguen a 0

	int32 Winner; //Cuando haya completado el nivel

	int32 Level; //Contamos los niveles

	int32 LifeTime; //Contamos las vidas

	int32 Score; //Contamos el puntaje

	bool CheckWinner; //Booleano para la verificacion del winner

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Creando el movimiento de la paleta
	virtual void MoveHorizontal(float _AxisValue);

	void LevelUp(int Up); //Incrementando el nivel

	void IncreaseOfLife(int life); //Incremento de vida

	void DecreaseOfLife(int life); //Decremento de vida

	FORCEINLINE void RestoreLevel(int _Level); //Restablecimiento de nivel

	void RestoreGameOver(int RestoreGameOver);	//Restablecimiento de game over

	void RestoreWinner(bool RestoreWinner); //Restablecimiento del winner

	void ScoreGame(int _Score); //Aumentamos el puntaje

	UFUNCTION(BlueprintCallable) //Devuelve el valor del nivel para los widgets
		int GetLevel() { return Level; }

	UFUNCTION(BlueprintCallable) //Devuelve el valor de las vidas para los widgets
		int GetLifeTime() { return LifeTime; }

	UFUNCTION(BlueprintCallable) //Devuelve el valor del game over para los widgets
		int GetGameOver() { return GameOver; }

	UFUNCTION(BlueprintCallable) // Devuelve el valor del winner si el nivel se completo
		int GetWinner() { return Winner; }

	UFUNCTION(BlueprintCallable) // Devuelve el valor del winner si el nivel se completo
		int GetScore() { return Score; }

private:
	// Punteros a las implementaciones de las capsulas
	class APaddle_PlayerController* Controller;
	class ABrickShield_* Reinforced;

	//Funciones y variables de la capsula de shoot
	float ShootTime; //Reinicio de disparo
	float TimeToSpawnShoot; //Tiempo para cada disparo
	bool Disparo; //Booleano para controlar la operatividad de la capsula
	FVector Projectile; //Angulo de lanzamiento de cada projectil
	FTimerHandle UnusedHandle; //Temporizador de operatividad de capsulas



	//creamos una variable entera con el límite de disparos
	int cantidadDisparo = 3;


	public:
	//el contador de disparos para que vaya disminuyendo
	void SetContador(int Disparos) { cantidadDisparo = cantidadDisparo - Disparos; };
	int GetContador() { return  cantidadDisparo;  }
};
