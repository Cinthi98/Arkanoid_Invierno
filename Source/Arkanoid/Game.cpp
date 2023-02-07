// Fill out your copyright notice in the Description page of Project Settings.


#include "Game.h"
#include "LevelBricks.h"

// Sets default values
AGame::AGame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGame::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGame::SetLevel(AActor* Level)
{
	LevelBuilder = Cast<ILevelBuilder>(Level);

	if (!LevelBuilder) { //Lanzamos un error si la conversion falla
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("¡Elenco no válido! Consulte Registro de salida para obtener más detalles."));
		UE_LOG(LogTemp, Error, TEXT("SetLevel(): ¡El actor no es un LevelBuilder! ¿Está seguro de que el actor implementa esa interfaz?"));
	}
}

void AGame::ConstructOfLevels(int _Level)
{
	//Registrar si el constructor es NULL
	if (!LevelBuilder) {
		UE_LOG(LogTemp, Error, TEXT("ConstructLevel1(): LevelBuilder es NULL, asegúrese de que este inicializado."));
		return;
	}
	else {
		//Creacion de los niveles
		if (1 == _Level) {
			LevelBuilder->BuildLevel1();
		}

		if (2 == _Level) {
			LevelBuilder->BuildLevel2();
		}

		if (3 == _Level) {
			LevelBuilder->BuildLevel3();
		}

		if (4 == _Level) {
			LevelBuilder->BuildLevel4();
		}

		if (5 == _Level) {
			LevelBuilder->BuildLevel5();
		}

		if (6 == _Level) {
			LevelBuilder->BuildLevel6();
		}

		if (7 == _Level) {
			LevelBuilder->BuildLevel7();
		}

		if (8 == _Level) {
			LevelBuilder->BuildLevel8();
		}
		
		if (9 == _Level) {
			LevelBuilder->BuildLevel9();
		}

		if (10 == _Level) {
			LevelBuilder->BuildLevel10();
		}
	}
}



