// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicCapsule.h"
#include "CreatorOfAntiCapsules.generated.h"
UCLASS()
class ARKANOID_API ACreatorOfAntiCapsules : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreatorOfAntiCapsules();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual ABasicCapsule* CreateCapsule(FString NameCapsule) PURE_VIRTUAL(ACreatorOfAntiCapsules::CreateCapsule, return nullptr;); //Funcion virtual pura a Basic Capsules

	ABasicCapsule* OrdenCapsule(FString Category); //Funcion para la creacion de capsulas de anti ayuda

};
