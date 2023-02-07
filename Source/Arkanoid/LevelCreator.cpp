// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCreator.h"
#include "LevelBricks.h"

// Sets default values
ALevelCreator::ALevelCreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelCreator::BeginPlay()
{
	Super::BeginPlay();

	//Spawn de los niveles
	LevelBricks = GetWorld()->SpawnActor<ALevelBricks>(ALevelBricks::StaticClass());

	//Adjuntamos al constructor
	LevelBricks->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called every frame
void ALevelCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelCreator::BuildLevel1()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine1(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el primer nivel
		LevelBricks->SetBrickLevel1();
		
	}
}

void ALevelCreator::BuildLevel2()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine2(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el segundo nivel
		LevelBricks->SetBrickLevel2();

	}
}

void ALevelCreator::BuildLevel3()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine3(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el tercer nivel
		LevelBricks->SetBrickLevel3();

	}
}

void ALevelCreator::BuildLevel4()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine4(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el cuarto nivel
		LevelBricks->SetBrickLevel4();

	}
}

void ALevelCreator::BuildLevel5()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine5(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el quinto nivel
		LevelBricks->SetBrickLevel5();

	}
}

void ALevelCreator::BuildLevel6()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine6(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el sexto nivel
		LevelBricks->SetBrickLevel6();

	}
}

void ALevelCreator::BuildLevel7()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine7(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el septimo nivel
		LevelBricks->SetBrickLevel7();

	}
}

void ALevelCreator::BuildLevel8()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine8(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el octavo nivel
		LevelBricks->SetBrickLevel8();

	}
}

void ALevelCreator::BuildLevel9()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine9(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el noveno nivel
		LevelBricks->SetBrickLevel9();

	}
}

void ALevelCreator::BuildLevel10()
{
	if (!LevelBricks)
	{
		UE_LOG(LogTemp, Error, TEXT("LevelBrickLine10(): LevelBricks es NULL, Asegurese de que este inicializado."));
		return;
	}
	else
	{
		//Creamos el decimo nivel
		LevelBricks->SetBrickLevel10();

	}
}

