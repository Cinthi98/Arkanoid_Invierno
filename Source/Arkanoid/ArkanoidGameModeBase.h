// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AArkanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	AArkanoidGameModeBase();

protected:
	virtual void BeginPlay() override;

	//Actor constructor
	UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
		class ALevelCreator* LevelCreator; //Puntero de a level creador
	//Actor del nivel
	UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
		class AGame* Game; //Puntero a cliente

	UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
		class ALevelBricks* LevelBricks; //Puntero a creador de niveles

	UPROPERTY()
		float Difficulty;

	bool CheckerLevel1; //Verificador de nivel 1
	bool CheckerLevel2;	//Verificador de nivel 2
	bool CheckerLevel3; //Verificador de nivel 3
	bool CheckerLevel4; //Verificador de nivel 4
	bool CheckerLevel5; //Verificador de nivel 5
	bool CheckerLevel6; //Verificador de nivel 6
	bool CheckerLevel7; //Verificador de nivel 7
	bool CheckerLevel8; //Verificador de nivel 8
	bool CheckerLevel9; //Verificador de nivel 9
	bool CheckerLevel10; //Verificador de nivel 10

public:

	void DifficultyIncrease(float time); //Incremenento de dificultad (proxima actualizacion)

	virtual void Tick(float DeltaSeconds) override;
	
private:

	float SpawnCapsuleAntiHelp; //Tiempo de spawn de capsula


};
