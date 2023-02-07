// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelBuilder.h"
#include "LevelCreator.generated.h"

UCLASS()
class ARKANOID_API ALevelCreator : public AActor, public ILevelBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelCreator();

private:

	UPROPERTY(VisibleAnywhere, Category = "Level")
		class ALevelBricks* LevelBricks; //Puntero al creador de niveles

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Funciones para la creacion de niveles
	virtual void BuildLevel1() override;
	virtual void BuildLevel2() override;
	virtual void BuildLevel3() override;
	virtual void BuildLevel4() override;
	virtual void BuildLevel5() override;
	virtual void BuildLevel6() override;
	virtual void BuildLevel7() override;
	virtual void BuildLevel8() override;
	virtual void BuildLevel9() override;
	virtual void BuildLevel10() override;

};
