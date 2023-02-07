// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArkanoidGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "CreatorOfAntiCapsules.h"
#include "CapsulesAntiHelp.h"
#include "LevelBricks.h"
#include "LevelCreator.h"
#include "Game.h"
#include "Paddle_PlayerController.h"
#include "Brick.h"
#include "Paddle.h"

AArkanoidGameModeBase::AArkanoidGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	SpawnCapsuleAntiHelp = 0.0f;
	Difficulty = 10.0f;

	CheckerLevel1 = true;
	CheckerLevel2 = true;
	CheckerLevel3 = true;
	CheckerLevel4 = true;
	CheckerLevel5 = true;
	CheckerLevel6 = true;
	CheckerLevel7 = true;
	CheckerLevel8 = true;
	CheckerLevel9 = true;
	CheckerLevel10 = true;
}

void AArkanoidGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreLevel(1); //Restaurador de nivel

	LevelCreator = GetWorld()->SpawnActor<ALevelCreator>(ALevelCreator::StaticClass());
	Game = GetWorld()->SpawnActor<AGame>(AGame::StaticClass());
	Game->SetLevel(LevelCreator);
	
}

void AArkanoidGameModeBase::DifficultyIncrease(float time)
{
	Difficulty = time;
}

void AArkanoidGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	APaddle_PlayerController* Controller = Cast<APaddle_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (Paddle->GetLevel() == 1 && CheckerLevel1 == true) {
		Game->ConstructOfLevels(1);
		CheckerLevel1 = false;
	}

	if (Paddle->GetLevel() == 2 && CheckerLevel2 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(2);
		CheckerLevel2 = false;
	}

	if (Paddle->GetLevel() == 3 && CheckerLevel3 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(3);
		CheckerLevel3 = false;
	}

	if (Paddle->GetLevel() == 4 && CheckerLevel4 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(4);
		CheckerLevel4 = false;
	}

	if (Paddle->GetLevel() == 5 && CheckerLevel5 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(5);
		CheckerLevel5 = false;
	}

	if (Paddle->GetLevel() == 6 && CheckerLevel6 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(6);
		CheckerLevel6 = false;
	}

	if (Paddle->GetLevel() == 7 && CheckerLevel7 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(7);
		CheckerLevel7 = false;
	}

	if (Paddle->GetLevel() == 8 && CheckerLevel8 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(8);
		CheckerLevel8 = false;
	}

	if (Paddle->GetLevel() == 9 && CheckerLevel9 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(9);
		CheckerLevel9 = false;
	}

	if (Paddle->GetLevel() == 10 && CheckerLevel10 == true) {
		Controller->DestroyBall();
		Controller->SpawnNewBall();
		Game->ConstructOfLevels(10);
		CheckerLevel10 = false;
	}

	SpawnCapsuleAntiHelp = SpawnCapsuleAntiHelp + DeltaSeconds;
	if (SpawnCapsuleAntiHelp >= Difficulty) {

		float RandomSpawn = FMath::RandRange(0, 150);
		ACreatorOfAntiCapsules *CapsuleCreator = GetWorld()->SpawnActor<ACapsulesAntiHelp>(ACapsulesAntiHelp::StaticClass());
		
		if (RandomSpawn >= 40.0f && RandomSpawn <= 90.0f) {
			ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule("AHeatlh");
		}
		
		if (RandomSpawn >= 10.0f && RandomSpawn <= 50.0f) {
			ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule("Destroy");
		}

		if (RandomSpawn >= 90.0f && RandomSpawn <= 110.0f) {
			ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule("Short");
		}

		if (RandomSpawn >= 60.0f && RandomSpawn <= 80.0f) {
			ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule("Speed");
		}

		if (RandomSpawn >= 70.0f && RandomSpawn <= 100.0f) {
			ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule("Static");
		}

		SpawnCapsuleAntiHelp = 0.0f;

	}
	
}

	