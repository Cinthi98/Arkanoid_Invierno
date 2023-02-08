// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_PlayerController.h"
#include "Kismet/GamePlayStatics.h" 
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"
#include "TwoBall.h"
#include "ThreeBall.h"
#include "Bomba.h"

APaddle_PlayerController::APaddle_PlayerController()
{
}

void APaddle_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
	SpawnNewBall();
}

void APaddle_PlayerController::Launch()
{
	MyBall->Launch();
}

void APaddle_PlayerController::DestroyBall()
{
	MyBall->Destroy();

	if (ThreeBall1 != nullptr) {
		ThreeBall1->Destroy();
	}

	if (ThreeBall2 != nullptr) {
		ThreeBall2->Destroy();
	}
	if (ThreeBall3 != nullptr) {
		ThreeBall3->Destroy();
	}
	
	if (TwoBall1 != nullptr) {
		TwoBall1->Destroy();
	}

	if (TwoBall2 != nullptr) {
		TwoBall2->Destroy();
	}
	
}

//Cambios para el examen de invierno
void APaddle_PlayerController::LaunchBombs()
{
	//Casteamos el pawn a un Mypaddle 
	auto MyPaddle = Cast<APaddle>(GetPawn());
	//Una vez casteado se usa un puntero y almacenamos su ubicacion 
	FVector UbiPaddle = MyPaddle->GetActorLocation();

	//Usano el casteo del pawn tomamos la propiedad getContador y validamos que sea mayor a 0
		if (MyPaddle->GetContador() > 0)
		{
			//Si es mayor a 0 se podra disparar 
			MyBomba = GetWorld()->SpawnActor<ABomba>(UbiPaddle + FVector(0, 0, 30), FRotator(90, 0, 90));
			//Si la bomba existe en el mundo no se podra reducir el contador y tampoco dispararà
			if (MyBomba != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Bombas %i"), MyPaddle->GetContador()));
				MyPaddle->SetContador(1);
			}

		}
		//Caso contrario que el contador sea 0 no se podra disparar y se mandara un mensaje
		else if (MyPaddle->GetContador() == 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No tienes mas bombas disponibles")));
		}


	if (!MyBomba)
	{
		MyBomba = nullptr;
	}
}

void APaddle_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &APaddle_PlayerController::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddle_PlayerController::Launch);
	//Este le asigna una tecla a la funcion launchBombs
	InputComponent->BindAction("Bomba", IE_Pressed, this, &APaddle_PlayerController::LaunchBombs);


}


void APaddle_PlayerController::MoveHorizontal(float _AxisValue)
{
	auto MyPaddle = Cast<APaddle>(GetPawn());

	if (MyPaddle) 
	{
		MyPaddle->MoveHorizontal(_AxisValue);
	}
}

void APaddle_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APaddle_PlayerController::SpawnNewBall()
{
	if (!MyBall) {
		MyBall = nullptr;
	}

	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SpawnInfo0);
	}
}

void APaddle_PlayerController::SpawnTwoBall()
{
	
	FVector Location = MyBall->GetActorLocation();
	TwoBall1 = GetWorld()->SpawnActor<ATwoBall>(TwoObj, Location, SpawnRotator);
	TwoBall2 = GetWorld()->SpawnActor<ATwoBall>(TwoObj, Location, SpawnRotator);


}

void APaddle_PlayerController::LaunchTwo()
{
	TwoBall1->LaunchTwoBall();
	TwoBall2->LaunchTwoBall();
}

void APaddle_PlayerController::SpawnThreeBall()
{

	FVector Location = MyBall->GetActorLocation();
	ThreeBall1 = GetWorld()->SpawnActor<AThreeBall>(ThreeObj, Location, SpawnRotator);
	ThreeBall2 = GetWorld()->SpawnActor<AThreeBall>(ThreeObj, Location, SpawnRotator);
	ThreeBall3 = GetWorld()->SpawnActor<AThreeBall>(ThreeObj, Location, SpawnRotator);
	

}

void APaddle_PlayerController::LaunchThree()
{
	ThreeBall1->LaunchThreeBall();
	ThreeBall2->LaunchThreeBall();
	ThreeBall3->LaunchThreeBall();
}


