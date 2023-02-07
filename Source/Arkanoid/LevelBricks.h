// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelInterfaces.h"
#include "LevelBricks.generated.h"

UCLASS()
class ARKANOID_API ALevelBricks : public AActor, public ILevelInterfaces
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelBricks();

private:

	class ABrick* Brick; //Brick normal

	class ABrickDoubleHit* BrickDouble; //Brick indestructible

	class ABrickShot* BrickShot; //Brick de disparo


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Establecemos las lineas de los bricks
	FORCEINLINE void SetBrickLevel1() override;
	FORCEINLINE void SetBrickLevel2() override;
	FORCEINLINE void SetBrickLevel3() override;
	FORCEINLINE void SetBrickLevel4() override;
	FORCEINLINE void SetBrickLevel5() override;
	FORCEINLINE void SetBrickLevel6() override;
	FORCEINLINE void SetBrickLevel7() override;
	FORCEINLINE void SetBrickLevel8() override;
	FORCEINLINE void SetBrickLevel9() override;
	FORCEINLINE void SetBrickLevel10() override;

};
