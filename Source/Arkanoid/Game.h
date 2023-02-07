// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelBuilder.h"
#include "Game.generated.h"

UCLASS()
class ARKANOID_API AGame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGame();

private:

	//Definimos el actor constructor del nivel
	ILevelBuilder* LevelBuilder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Estableciendo el actor del nivel
	void SetLevel(AActor* Level);

	//Creacion del nivel 1
	void ConstructOfLevels(int _Level);


};
