// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelBricks.h"
#include "Brick.h"
#include "BrickDoubleHit.h"
#include "BrickShot.h"
#include "Paddle.h"
#include "Kismet/GameplayStatics.h"
#include "ArkanoidGameModeBase.h"


// Sets default values
ALevelBricks::ALevelBricks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelBricks::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelBricks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelBricks::SetBrickLevel1()
{
	Brick->RestoreLevel(70);

	//Primera linea
	FVector Spawn1(-150.0f, 0.0f, 450.0f);
	FVector Spawn2(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn1, FRotator::ZeroRotator);

		Spawn1 = Spawn1 + Spawn2;
	}

	//Segunda Linea
	FVector Spawn3(-150.0f, 0.0f, 430.0f);
	FVector Spawn4(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn3, FRotator::ZeroRotator);

		Spawn3 = Spawn3 + Spawn4;
	}

	//Tercera Linea
	FVector Spawn5(-150.0f, 0.0f, 410.0f);
	FVector Spawn6(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn5, FRotator::ZeroRotator);

		Spawn5 = Spawn5 + Spawn6;
	}

	//Cuarta Linea
	FVector Spawn7(-150.0f, 0.0f, 390.0f);
	FVector Spawn8(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn7, FRotator::ZeroRotator);

		Spawn7 = Spawn7 + Spawn8;
	}

	//Quinta Linea
	FVector Spawn9(-150.0f, 0.0f, 370.0f);
	FVector Spawn10(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn9, FRotator::ZeroRotator);

		Spawn9 = Spawn9 + Spawn10;
	}
	
	//Sexta Linea
	FVector Spawn11(-150.0f, 0.0f, 350.0f);
	FVector Spawn12(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn11, FRotator::ZeroRotator);

		Spawn11 = Spawn11 + Spawn12;
	}

	//Septima Linea
	FVector Spawn13(-150.0f, 0.0f, 330.0f);
	FVector Spawn14(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn13, FRotator::ZeroRotator);

		Spawn13 = Spawn13 + Spawn14;
	}

	//Octava Linea
	FVector Spawn15(-150.0f, 0.0f, 310.0f);
	FVector Spawn16(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

		Spawn15 = Spawn15 + Spawn16;
	}

	//Novena Linea
	FVector Spawn17(-150.0f, 0.0f, 290.0f);
	FVector Spawn18(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn17, FRotator::ZeroRotator);

		Spawn17 = Spawn17 + Spawn18;
	}

	//Decima Linea
	FVector Spawn19(-150.0f, 0.0f, 270.0f);
	FVector Spawn20(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn19, FRotator::ZeroRotator);

		Spawn19 = Spawn19 + Spawn20;
	}
}

void ALevelBricks::SetBrickLevel2()
{
	Brick->RestoreLevel(70);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera linea
	FVector Spawn1(-60.0f, 0.0f, 450.0f);
	FVector Spawn2(120.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn1, FRotator::ZeroRotator);

		Spawn1 = Spawn1 + Spawn2;
	}

	FVector Spawn3(-25.0f, 0.0f, 450.0f);
	FVector Spawn4(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn3, FRotator::ZeroRotator);

		Spawn3 = Spawn3 + Spawn4;
	}

	//SegundaLinea
	FVector Spawn5(-110.0f, 0.0f, 430.0f);
	FVector Spawn6(220.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn5, FRotator::ZeroRotator);

		Spawn5 = Spawn5 + Spawn6;
	}

	FVector Spawn7(-75.0f, 0.0f, 430.0f);
	FVector Spawn8(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 4; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn7, FRotator::ZeroRotator);

		Spawn7 = Spawn7 + Spawn8;
	}

	//TerceraLinea
	FVector Spawn9(-160.0f, 0.0f, 410.0f);
	FVector Spawn10(320.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn9, FRotator::ZeroRotator);

		Spawn9 = Spawn9 + Spawn10;
	}

	FVector Spawn11(-40.0f, 0.0f, 410.0f);
	FVector Spawn12(80.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn11, FRotator::ZeroRotator);

		Spawn11 = Spawn11 + Spawn12;
	}

	FVector Spawn13(-125.0f, 0.0f, 410.0f);
	FVector Spawn14(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn13, FRotator::ZeroRotator);

		Spawn13 = Spawn13 + Spawn14;
	}

	FVector Spawn15(0.0f, 0.0f, 410.0f);

	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

	FVector Spawn16(75.0f, 0.0f, 410.0f);
	FVector Spawn17(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn16, FRotator::ZeroRotator);

		Spawn16 = Spawn16 + Spawn17;
	}

	//CuartaLinea
	FVector Spawn18(-160.0f, 0.0f, 390.0f);
	FVector Spawn19(320.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn18, FRotator::ZeroRotator);

		Spawn18 = Spawn18 + Spawn19;
	}

	FVector Spawn20(-75.0f, 0.0f, 390.0f);
	FVector Spawn21(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 4; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn20, FRotator::ZeroRotator);

		Spawn20 = Spawn20 + Spawn21;
	}

	//QuintaLinea
	FVector Spawn22(-160.0f, 0.0f, 370.0f);
	FVector Spawn23(320.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn22, FRotator::ZeroRotator);

		Spawn22 = Spawn22 + Spawn23;
	}

	FVector Spawn24(0.0f, 0.0f, 370.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn24, FRotator::ZeroRotator);

	FVector Spawn25(-90.0f, 0.0f, 370.0f);
	FVector Spawn26(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn25, FRotator::ZeroRotator);

		Spawn25 = Spawn25 + Spawn26;
	}

	FVector Spawn27(40.0f, 0.0f, 370.0f);
	FVector Spawn28(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn27, FRotator::ZeroRotator);

		Spawn27 = Spawn27 + Spawn28;
	}

	//SextaLinea
	FVector Spawn29(-160.0f, 0.0f, 350.0f);
	FVector Spawn30(320.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn29, FRotator::ZeroRotator);

		Spawn29 = Spawn29 + Spawn30;
	}

	FVector Spawn31(-115.0f, 0.0f, 350.0f);
	FVector Spawn32(230.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn31, FRotator::ZeroRotator);

		Spawn31 = Spawn31 + Spawn32;
	}

	FVector Spawn33(-75.0f, 0.0f, 350.0f);
	FVector Spawn34(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 4; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn33, FRotator::ZeroRotator);

		Spawn33 = Spawn33 + Spawn34;
	}

	//SeptimaLinea
	FVector Spawn35(-160.0f, 0.0f, 330.0f);
	FVector Spawn36(320.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn35, FRotator::ZeroRotator);

		Spawn35 = Spawn35 + Spawn36;
	}

	FVector Spawn37(0.0f, 0.0f, 330.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn37, FRotator::ZeroRotator);

	FVector Spawn38(-90.0f, 0.0f, 330.0f);
	FVector Spawn39(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn38, FRotator::ZeroRotator);

		Spawn38 = Spawn38 + Spawn39;
	}

	FVector Spawn40(40.0f, 0.0f, 330.0f);
	FVector Spawn41(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn40, FRotator::ZeroRotator);

		Spawn40 = Spawn40 + Spawn41;
	}

	//OctavaLinea
	FVector Spawn42(-160.0f, 0.0f, 310.0f);
	FVector Spawn43(320.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn42, FRotator::ZeroRotator);

		Spawn42 = Spawn42 + Spawn43;
	}

	FVector Spawn44(-65.0f, 0.0f, 310.0f);
	FVector Spawn45(130.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn44, FRotator::ZeroRotator);

		Spawn44 = Spawn44 + Spawn45;
	}

	FVector Spawn46(-25.0f, 0.0f, 310.0f);
	FVector Spawn47(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn46, FRotator::ZeroRotator);

		Spawn46 = Spawn46 + Spawn47;
	}

	//NovenaLinea
	FVector Spawn48(-160.0f, 0.0f, 290.0f);
	FVector Spawn49(320.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn48, FRotator::ZeroRotator);

		Spawn48 = Spawn48 + Spawn49;
	}

	FVector Spawn50(0.0f, 0.0f, 290.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn50, FRotator::ZeroRotator);

	FVector Spawn51(-90.0f, 0.0f, 290.0f);
	FVector Spawn52(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn51, FRotator::ZeroRotator);

		Spawn51 = Spawn51 + Spawn52;
	}

	FVector Spawn53(40.0f, 0.0f, 290.0f);
	FVector Spawn54(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn53, FRotator::ZeroRotator);

		Spawn53 = Spawn53 + Spawn54;
	}

	//DecimaLinea
	FVector Spawn55(-75.0f, 0.0f, 270.0f);
	FVector Spawn56(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 4; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn55, FRotator::ZeroRotator);

		Spawn55 = Spawn55 + Spawn56;
	}

	//UnDecimaLinea
	FVector Spawn57(-40.0f, 0.0f, 250.0f);
	FVector Spawn58(80.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn57, FRotator::ZeroRotator);

		Spawn57 = Spawn57 + Spawn58;
	}

	FVector Spawn59(0.0f, 0.0f, 250.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn59, FRotator::ZeroRotator);

	//TreDecimaLinea
	FVector Spawn60(-25.0f, 0.0f, 230.0f);
	FVector Spawn61(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn60, FRotator::ZeroRotator);

		Spawn60 = Spawn60 + Spawn61;
	}

	//CuatriDecimaLinea
	FVector Spawn62(0.0f, 0.0f, 210.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn62, FRotator::ZeroRotator);
}

void ALevelBricks::SetBrickLevel3()
{
	Brick->RestoreLevel(25);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera Linea

	FVector Spawn1(-140.0f, 0.0f, 430.0f);
	FVector Spawn2(90.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn1, FRotator::ZeroRotator);

		Spawn1 = Spawn1 + Spawn2;
	}
	FVector Spawn3(50.0f, 0.0f, 420.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn3, FRotator::ZeroRotator);

	FVector Spawn4(140.0f, 0.0f, 420.0f);

	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn4, FRotator::ZeroRotator);

	//Segunda Linea

	FVector Spawn5(-90.0f, 0.0f, 390.0f);
	FVector Spawn6(90.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn5, FRotator::ZeroRotator);

		Spawn5 = Spawn5 + Spawn6;
	}

	FVector Spawn7(50.0f, 0.0f, 402.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn7, FRotator::ZeroRotator);

	FVector Spawn8(100.0f, 0.0f, 380.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn8, FRotator::ZeroRotator);

	//Tercera Linea

	FVector Spawn9(-120.0f, 0.0f, 350.0f);
	FVector Spawn10(90.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn9, FRotator::ZeroRotator);

		Spawn9 = Spawn9 + Spawn10;
	}

	FVector Spawn11(130.0f, 0.0f, 350.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn11, FRotator::ZeroRotator);

	//Cuarta Linea

	FVector Spawn12(-120.0f, 0.0f, 300.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn12, FRotator::ZeroRotator);

	FVector Spawn13(20.0f, 0.0f, 310.0f);
	FVector Spawn14(90.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn13, FRotator::ZeroRotator);

		Spawn13 = Spawn13 + Spawn14;
	}

	//Quinta Linea

	FVector Spawn15(-120.0f, 0.0f, 282.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

	FVector Spawn16(20.0f, 0.0f, 292.0f);
	FVector Spawn17(90.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn16, FRotator::ZeroRotator);

		Spawn16 = Spawn16 + Spawn17;
	}

	//Sexta Linea

	FVector Spawn18(-40.0f, 0.0f, 250.0f);
	FVector Spawn19(110.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn18, FRotator::ZeroRotator);

		Spawn18 = Spawn18 + Spawn19;
	}

	FVector Spawn20(-40.0f, 0.0f, 232.0f);
	FVector Spawn21(110.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn20, FRotator::ZeroRotator);

		Spawn20 = Spawn20 + Spawn21;
	}

	//Septima Linea

	FVector Spawn22(-110.0f, 0.0f, 190.0f);
	FVector Spawn23(110.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn22, FRotator::ZeroRotator);

		Spawn22 = Spawn22 + Spawn23;
	}

	FVector Spawn24(-110.0f, 0.0f, 172.0f);
	FVector Spawn25(110.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn24, FRotator::ZeroRotator);

		Spawn24 = Spawn24 + Spawn25;
	}

}

void ALevelBricks::SetBrickLevel4()
{
	Brick->RestoreLevel(36);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera Linea

	FVector Spawn1(-140.0f, 0.0f, 430.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn1, FRotator::ZeroRotator);

	FVector Spawn2(-90.0f, 0.0f, 420.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn2, FRotator::ZeroRotator);

	FVector Spawn3(-50.0f, 0.0f, 430.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn3, FRotator::ZeroRotator);

	FVector Spawn4(-10.0f, 0.0f, 420.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn4, FRotator::ZeroRotator);

	FVector Spawn5(40.0f, 0.0f, 410.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn5, FRotator::ZeroRotator);

	FVector Spawn6(90.0f, 0.0f, 430.0f);
	FVector Spawn7(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn6, FRotator::ZeroRotator);

		Spawn6 = Spawn6 + Spawn7;
	}

	//Segunda Linea

	FVector Spawn8(-130.0f, 0.0f, 370.0f);
	FVector Spawn9(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn8, FRotator::ZeroRotator);

		Spawn8 = Spawn8 + Spawn9;
	}

	FVector Spawn10(80.0f, 0.0f, 370.0f);
	FVector Spawn11(50.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn10, FRotator::ZeroRotator);

		Spawn10 = Spawn10 + Spawn11;
	}

	//Tercera Linea

	FVector Spawn12(-120.0f, 0.0f, 320.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn12, FRotator::ZeroRotator);

	//Cuerta Linea

	FVector Spawn13(-130.0f, 0.0f, 270.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn13, FRotator::ZeroRotator);


	//Quinta Linea

	FVector Spawn14(-120.0f, 0.0f, 220.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn14, FRotator::ZeroRotator);


	//Sexta Linea

	FVector Spawn15(0.0f, 0.0f, 348.0f);
	FVector Spawn16(0.0f, 0.0f, -18.0f);
	for (int i = 1; i <= 7; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

		Spawn15 = Spawn15 + Spawn16;
	}

	//Septima Linea

	FVector Spawn17(-33.0f, 0.0f, 315.0f);
	FVector Spawn18(0.0f, 0.0f, -43.0f);
	FRotator SpawnR1(90.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn17, SpawnR1);

		Spawn17 = Spawn17 + Spawn18;
	}

	FVector Spawn19(33.0f, 0.0f, 315.0f);
	FVector Spawn20(0.0f, 0.0f, -43.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn19, SpawnR1);

		Spawn19 = Spawn19 + Spawn20;
	}

	//Octava Linea

	FVector Spawn21(-51.0f, 0.0f, 292.0f);
	FVector Spawn22(102.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn21, SpawnR1);

		Spawn21 = Spawn21 + Spawn22;
	}

	//Novena Linea

	FVector Spawn23(102.0f, 0.0f, 293.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn23, SpawnR1);

	//Decima Linea


	FVector Spawn24(102.0f, 0.0f, 260.0f);
	FVector Spawn25(0.0f, 0.0f, -18.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn24, FRotator::ZeroRotator);

		Spawn24 = Spawn24 + Spawn25;
	}

	//Onceava Linea

	FVector Spawn26(94.0f, 0.0f, 209.0f);
	FVector Spawn27(17.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn26, SpawnR1);

		Spawn26 = Spawn26 + Spawn27;
	}

	FVector Spawn28(94.0f, 0.0f, 162.0f);
	FVector Spawn29(17.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn28, SpawnR1);

		Spawn28 = Spawn28 + Spawn29;
	}

	//Doceava Linea

	FVector Spawn30(77.0f, 0.0f, 140.0f);
	FVector Spawn31(51.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn30, SpawnR1);

		Spawn30 = Spawn30 + Spawn31;
	}
}

void ALevelBricks::SetBrickLevel5()
{
	Brick->RestoreLevel(26);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera Linea

	FVector Spawn1(-130.0f, 0.0f, 430.0f);
	FVector Spawn2(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn1, FRotator::ZeroRotator);

		Spawn1 = Spawn1 + Spawn2;
	}

	FVector Spawn3(40.0f, 0.0f, 430.0f);
	FVector Spawn4(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn3, FRotator::ZeroRotator);

		Spawn3 = Spawn3 + Spawn4;
	}

	//Segunda Linea

	FVector Spawn5(-110.0f, 0.0f, 412.0f);
	FVector Spawn6(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn5, FRotator::ZeroRotator);

		Spawn5 = Spawn5 + Spawn6;
	}

	FVector Spawn7(60.0f, 0.0f, 412.0f);
	FVector Spawn8(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn7, FRotator::ZeroRotator);

		Spawn7 = Spawn7 + Spawn8;
	}

	//Tercera Linea

	FVector Spawn9(-83.0f, 0.0f, 394.0f);
	FVector Spawn10(170.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn9, FRotator::ZeroRotator);

		Spawn9 = Spawn9 + Spawn10;
	}

	//Cuarta Linea

	FVector Spawn11(-50.0f, 0.0f, 350.0f);
	FVector Spawn12(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn11, FRotator::ZeroRotator);

		Spawn11 = Spawn11 + Spawn12;
	}

	FVector Spawn13(-140.0f, 0.0f, 350.0f);
	FVector Spawn14(280.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn13, FRotator::ZeroRotator);

		Spawn13 = Spawn13 + Spawn14;
	}

	//Quinta Linea

	FVector Spawn15(-30.0f, 0.0f, 332.0f);
	FVector Spawn16(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

		Spawn15 = Spawn15 + Spawn16;
	}

	//Sexta Linea

	FVector Spawn17(-3.0f, 0.0f, 314.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn17, FRotator::ZeroRotator);

	//Septima Linea

	FVector Spawn18(-110.0f, 0.0f, 310.0f);
	FVector Spawn19(210.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn18, FRotator::ZeroRotator);

		Spawn18 = Spawn18 + Spawn19;
	}

	//Octava Linea

	FVector Spawn20(-140.0f, 0.0f, 260.0f);
	FVector Spawn21(60.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn20, FRotator::ZeroRotator);

		Spawn20 = Spawn20 + Spawn21;
	}

	//Novena Linea

	FVector Spawn22(50.0f, 0.0f, 260.0f);
	FVector Spawn23(70.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn22, FRotator::ZeroRotator);

		Spawn22 = Spawn22 + Spawn23;
	}

}

void ALevelBricks::SetBrickLevel6()
{

	Brick->RestoreLevel(48);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera linea
	FVector Spawn1(0.0f, 0.0f, 444.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn1, FRotator::ZeroRotator);

	//Segunda Linea
	FVector Spawn2(-96.0f, 0.0f, 426.0f);
	FVector Spawn3(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn2, FRotator::ZeroRotator);

		Spawn2 = Spawn2 + Spawn3;
	}

	FVector Spawn4(72.0f, 0.0f, 426.0f);
	FVector Spawn5(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn4, FRotator::ZeroRotator);

		Spawn4 = Spawn4 + Spawn5;
	}

	FVector Spawn6(-24.0f, 0.0f, 426.0f);
	FVector Spawn7(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn6, FRotator::ZeroRotator);

		Spawn6 = Spawn6 + Spawn7;
	}

	//Tercera Linea
	FVector Spawn8(-96.0f, 0.0f, 408.0f);
	FVector Spawn9(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 9; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn8, FRotator::ZeroRotator);

		Spawn8 = Spawn8 + Spawn9;
	}

	//Cuarta Linea
	FVector Spawn10(-96.0f, 0.0f, 390.0f);
	FVector Spawn11(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 9; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn10, FRotator::ZeroRotator);

		Spawn10 = Spawn10 + Spawn11;
	}

	FVector Spawn12(70.0f, 0.0f, 390.0f);
	FVector Spawn13(-140.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn12, FRotator::ZeroRotator);

		Spawn12 = Spawn12 + Spawn13;
	}

	//Quinta Linea
	FVector Spawn14(-72.0f, 0.0f, 372.0f);
	FVector Spawn15(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn14, FRotator::ZeroRotator);

		Spawn14 = Spawn14 + Spawn15;
	}

	FVector Spawn16(24.0f, 0.0f, 372.0f);
	FVector Spawn17(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn16, FRotator::ZeroRotator);

		Spawn16 = Spawn16 + Spawn17;
	}

	//Sexta Linea
	FVector Spawn18(-24.0f, 0.0f, 354.0f);
	FVector Spawn19(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn18, FRotator::ZeroRotator);

		Spawn18 = Spawn18 + Spawn19;
	}

	//Septima Linea
	FVector Spawn20(-24.0f, 0.0f, 336.0f);
	FVector Spawn21(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn20, FRotator::ZeroRotator);

		Spawn20 = Spawn20 + Spawn21;
	}

	//Octava Linea
	FVector Spawn22(-144.0f, 0.0f, 318.0f);
	FVector Spawn23(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn22, FRotator::ZeroRotator);

		Spawn22 = Spawn22 + Spawn23;
	}

	FVector Spawn24(-24.0f, 0.0f, 318.0f);
	FVector Spawn25(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn24, FRotator::ZeroRotator);

		Spawn24 = Spawn24 + Spawn25;
	}

	FVector Spawn26(106.0f, 0.0f, 318.0f);
	FVector Spawn27(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn26, FRotator::ZeroRotator);

		Spawn26 = Spawn26 + Spawn27;
	}

	//Novena Linea
	FVector Spawn28(-120.0f, 0.0f, 300.0f);
	FVector Spawn29(120.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn28, FRotator::ZeroRotator);

		Spawn28 = Spawn28 + Spawn29;
	}

	FVector Spawn30(130.0f, 0.0f, 300.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn30, FRotator::ZeroRotator);
}

void ALevelBricks::SetBrickLevel7()
{
	Brick->RestoreLevel(86);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera Linea
	FVector Spawn1(-30.0f, 0.0f, 427.0f);
	FVector Spawn2(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn1, FRotator::ZeroRotator);

		Spawn1 = Spawn1 + Spawn2;
	}

	//Segunda Linea
	FVector Spawn3(-30.0f, 0.0f, 410.0f);
	FVector Spawn4(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn3, FRotator::ZeroRotator);

		Spawn3 = Spawn3 + Spawn4;
	}

	FVector Spawn5(-66.0f, 0.0f, 410.0f);
	FVector Spawn6(120.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn5, FRotator::ZeroRotator);

		Spawn5 = Spawn5 + Spawn6;
	}

	//Tercera Linea
	FVector Spawn7(-78.0f, 0.0f, 393.0f);
	FVector Spawn8(48.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn7, FRotator::ZeroRotator);

		Spawn7 = Spawn7 + Spawn8;
	}

	FVector Spawn9(6.0f, 0.0f, 393.0f);
	FVector Spawn10(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 4; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn9, FRotator::ZeroRotator);

		Spawn9 = Spawn9 + Spawn10;
	}

	//Cuarta Linea
	FVector Spawn11(-78.0f, 0.0f, 375.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn11, FRotator::ZeroRotator);

	FVector Spawn12(-114.0f, 0.0f, 375.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn12, FRotator::ZeroRotator);

	FVector Spawn13(90.0f, 0.0f, 375.0f);
	BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn13, FRotator::ZeroRotator);

	FVector Spawn14(-42.0f, 0.0f, 375.0f);
	FVector Spawn15(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn14, FRotator::ZeroRotator);

		Spawn14 = Spawn14 + Spawn15;
	}

	//Quinta Linea
	FVector Spawn16(-114.0f, 0.0f, 357.0f);
	BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn16, FRotator::ZeroRotator);

	FVector Spawn17(-78.0f, 0.0f, 357.0f);
	BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn17, FRotator::ZeroRotator);

	FVector Spawn18(-30.0f, 0.0f, 357.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn18, FRotator::ZeroRotator);

	FVector Spawn19(6.0f, 0.0f, 357.0f);
	FVector Spawn20(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 6; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn19, FRotator::ZeroRotator);

		Spawn19 = Spawn19 + Spawn20;
	}

	//Sexta Linea
	FVector Spawn21(-78.0f, 0.0f, 339.0f);
	BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn21, FRotator::ZeroRotator);

	FVector Spawn22(-30.0f, 0.0f, 339.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn22, FRotator::ZeroRotator);

	FVector Spawn23(6.0f, 0.0f, 339.0f);
	FVector Spawn24(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 6; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn23, FRotator::ZeroRotator);

		Spawn23 = Spawn23 + Spawn24;
	}

	//Septima Linea
	FVector Spawn25(-90.0f, 0.0f, 321.0f);
	FVector Spawn26(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 10; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn25, FRotator::ZeroRotator);

		Spawn25 = Spawn25 + Spawn26;
	}

	//Octava Linea
	FVector Spawn27(-90.0f, 0.0f, 303.0f);
	FVector Spawn28(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 10; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn27, FRotator::ZeroRotator);

		Spawn27 = Spawn27 + Spawn28;
	}

	//Novena Linea
	FVector Spawn29(-90.0f, 0.0f, 285.0f);
	FVector Spawn30(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 9; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn29, FRotator::ZeroRotator);

		Spawn29 = Spawn29 + Spawn30;
	}

	//Decima Linea
	FVector Spawn31(-90.0f, 0.0f, 267.0f);
	FVector Spawn32(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 8; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn31, FRotator::ZeroRotator);

		Spawn31 = Spawn31 + Spawn32;
	}

	//Onceava Linea
	FVector Spawn33(-90.0f, 0.0f, 249.0f);
	FVector Spawn34(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn33, FRotator::ZeroRotator);

		Spawn33 = Spawn33 + Spawn34;
	}

	FVector Spawn35(30.0f, 0.0f, 249.0f);
	FVector Spawn36(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn35, FRotator::ZeroRotator);

		Spawn35 = Spawn35 + Spawn36;
	}

	//Decima Linea
	FVector Spawn37(-90.0f, 0.0f, 231.0f);
	FVector Spawn38(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn37, FRotator::ZeroRotator);

		Spawn37 = Spawn37 + Spawn38;
	}

	FVector Spawn39(30.0f, 0.0f, 231.0f);
	FVector Spawn40(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn39, FRotator::ZeroRotator);

		Spawn39 = Spawn39 + Spawn40;
	}

}

void ALevelBricks::SetBrickLevel8()
{

	Brick->RestoreLevel(44);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primer Linea
	FVector Spawn1(-90.0f, 0.0f, 427.0f);
	FVector Spawn2(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 8; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn1, FRotator::ZeroRotator);

		Spawn1 = Spawn1 + Spawn2;
	}

	//Segunda Linea
	FVector Spawn3(-90.0f, 0.0f, 410.0f);
	FVector Spawn4(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 8; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn3, FRotator::ZeroRotator);

		Spawn3 = Spawn3 + Spawn4;
	}

	//Tercera Linea
	FVector Spawn5(-90.0f, 0.0f, 393.0f);
	FVector Spawn6(168.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn5, FRotator::ZeroRotator);

		Spawn5 = Spawn5 + Spawn6;
	}

	FVector Spawn7(-18.0f, 0.0f, 393.0f);
	FVector Spawn8(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn7, FRotator::ZeroRotator);

		Spawn7 = Spawn7 + Spawn8;
	}

	//Cuarta Linea
	FVector Spawn9(-90.0f, 0.0f, 375.0f);
	FVector Spawn10(168.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn9, FRotator::ZeroRotator);

		Spawn9 = Spawn9 + Spawn10;
	}

	FVector Spawn11(-18.0f, 0.0f, 375.0f);
	FVector Spawn12(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn11, FRotator::ZeroRotator);

		Spawn11 = Spawn11 + Spawn12;
	}


	//Quinta Linea
	FVector Spawn13(-90.0f, 0.0f, 357.0f);
	FVector Spawn14(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn13, FRotator::ZeroRotator);

		Spawn13 = Spawn13 + Spawn14;
	}

	FVector Spawn15(30.0f, 0.0f, 357.0f);
	FVector Spawn16(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn15, FRotator::ZeroRotator);

		Spawn15 = Spawn15 + Spawn16;
	}


	//Sexta Linea
	FVector Spawn17(-90.0f, 0.0f, 339.0f);
	FVector Spawn18(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn17, FRotator::ZeroRotator);

		Spawn17 = Spawn17 + Spawn18;
	}

	FVector Spawn19(54.0f, 0.0f, 339.0f);
	FVector Spawn20(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn19, FRotator::ZeroRotator);

		Spawn19 = Spawn19 + Spawn20;
	}


	//Septima Linea
	FVector Spawn21(-90.0f, 0.0f, 321.0f);
	FVector Spawn22(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn21, FRotator::ZeroRotator);

		Spawn21 = Spawn21 + Spawn22;
	}

	FVector Spawn23(54.0f, 0.0f, 321.0f);
	FVector Spawn24(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn23, FRotator::ZeroRotator);

		Spawn23 = Spawn23 + Spawn24;
	}


	//Octava Linea
	FVector Spawn25(-90.0f, 0.0f, 303.0f);
	FVector Spawn26(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn25, FRotator::ZeroRotator);

		Spawn25 = Spawn25 + Spawn26;
	}

	FVector Spawn27(-18.0f, 0.0f, 303.0f);
	FVector Spawn28(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn27, FRotator::ZeroRotator);

		Spawn27 = Spawn27 + Spawn28;
	}

	FVector Spawn29(54.0f, 0.0f, 303.0f);
	FVector Spawn30(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn29, FRotator::ZeroRotator);

		Spawn29 = Spawn29 + Spawn30;
	}
}

void ALevelBricks::SetBrickLevel9()
{

	Brick->RestoreLevel(48);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera Linea
	FVector Spawn1(-150.0f, 0.0f, 427.0f);
	Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn1, FRotator::ZeroRotator);


	FVector Spawn2(-90.0f, 0.0f, 427.0f);
	FVector Spawn3(60.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn2, FRotator::ZeroRotator);

		Spawn2 = Spawn2 + Spawn3;
	}

	//Segunda Linea
	FVector Spawn4(-150.0f, 0.0f, 397.0f);
	FVector Spawn5(120.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 3; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn4, FRotator::ZeroRotator);

		Spawn4 = Spawn4 + Spawn5;
	}

	FVector Spawn6(-102.0f, 0.0f, 397.0f);
	FVector Spawn7(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn6, FRotator::ZeroRotator);

		Spawn6 = Spawn6 + Spawn7;
	}

	FVector Spawn8(18.0f, 0.0f, 397.0f);
	FVector Spawn9(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn8, FRotator::ZeroRotator);

		Spawn8 = Spawn8 + Spawn9;
	}

	FVector Spawn10(138.0f, 0.0f, 397.0f);
	FVector Spawn11(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn10, FRotator::ZeroRotator);

		Spawn10 = Spawn10 + Spawn11;
	}

	//Tercera Linea
	FVector Spawn12(-150.0f, 0.0f, 367.0f);
	FVector Spawn13(60.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 6; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn12, FRotator::ZeroRotator);

		Spawn12 = Spawn12 + Spawn13;
	}

	//Cuarta Linea
	FVector Spawn14(-150.0f, 0.0f, 337.0f);
	BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn14, FRotator::ZeroRotator);

	FVector Spawn15(-90.0f, 0.0f, 337.0f);
	FVector Spawn16(60.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 5; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

		Spawn15 = Spawn15 + Spawn16;
	}

	//Quinta Linea
	FVector Spawn17(-150.0f, 0.0f, 307.0f);
	FVector Spawn18(60.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 6; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn17, FRotator::ZeroRotator);

		Spawn17 = Spawn17 + Spawn18;
	}

	//Sexta Linea
	FVector Spawn19(-150.0f, 0.0f, 277.0f);
	FVector Spawn20(300.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn19, FRotator::ZeroRotator);

		Spawn19 = Spawn19 + Spawn20;
	}

	FVector Spawn21(-30.0f, 0.0f, 277.0f);
	FVector Spawn22(60.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn21, FRotator::ZeroRotator);

		Spawn21 = Spawn21 + Spawn22;
	}

	FVector Spawn23(-102.0f, 0.0f, 277.0f);
	FVector Spawn24(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn23, FRotator::ZeroRotator);

		Spawn23 = Spawn23 + Spawn24;
	}

	FVector Spawn25(78.0f, 0.0f, 277.0f);
	FVector Spawn26(24.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 2; i++) {

		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn25, FRotator::ZeroRotator);

		Spawn25 = Spawn25 + Spawn26;
	}

	//Septima Linea
	FVector Spawn27(-150.0f, 0.0f, 247.0f);
	FVector Spawn28(60.0f, 0.0f, 0.0f);
	for (int i = 1; i <= 6; i++) {

		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn27, FRotator::ZeroRotator);

		Spawn27 = Spawn27 + Spawn28;
	}

	FVector Spawn29(150.0f, 0.0f, 337.0f);
	BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn29, FRotator::ZeroRotator);

}

void ALevelBricks::SetBrickLevel10()
{

	Brick->RestoreLevel(30);

	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->RestoreWinner(true);

	//Primera linea
	FVector Spawn(-55.0f, 0.0f, 435.0f);
	FVector Spawn2(110.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn, FRotator::ZeroRotator);

		Spawn = Spawn + Spawn2;
	}

	//Segunda linea
	FVector Spawn3(-35.0f, 0.0f, 400.0f);
	FVector Spawn4(70.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn3, FRotator(90.0f, 0.0f, 0.0f));

		Spawn3 = Spawn3 + Spawn4;
	}

	//Tercera linea
	FVector Spawn5(-55.0f, 0.0f, 375.0f);
	FVector Spawn6(110.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn5, FRotator(90.0f, 0.0f, 0.0f));

		Spawn5 = Spawn5 + Spawn6;
	}

	FVector Spawn7(-15.0f, 0.0f, 375.0f);
	FVector Spawn8(30.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn7, FRotator(90.0f, 0.0f, 0.0f));

		Spawn7 = Spawn7 + Spawn8;
	}

	//Cuarta linea
	FVector Spawn9(-71.0f, 0.0f, 350.0f);
	FVector Spawn10(142.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		BrickShot = GetWorld()->SpawnActor<ABrickShot>(ABrickShot::StaticClass(), Spawn9, FRotator(90.0f, 0.0f, 0.0f));

		Spawn9 = Spawn9 + Spawn10;
	}

	//Quinta linea
	FVector Spawn11(-90.0f, 0.0f, 325.0f);
	FVector Spawn12(90.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 3; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn11, FRotator(90.0f, 0.0f, 0.0f));

		Spawn11 = Spawn11 + Spawn12;
	}

	//Sexta linea
	FVector Spawn13(-35.0f, 0.0f, 340.0f);
	FVector Spawn14(70.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn13, FRotator::ZeroRotator);

		Spawn13 = Spawn13 + Spawn14;
	}

	FVector Spawn15(-35.0f, 0.0f, 320.0f);
	FVector Spawn16(70.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn15, FRotator::ZeroRotator);

		Spawn15 = Spawn15 + Spawn16;
	}

	//Septima linea
	FVector Spawn17(-90.0f, 0.0f, 291.0f);
	FVector Spawn18(180.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn17, FRotator::ZeroRotator);

		Spawn17 = Spawn17 + Spawn18;
	}

	FVector Spawn19(-55.0f, 0.0f, 285.0f);
	FVector Spawn20(110.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Spawn19, FRotator::ZeroRotator);

		Spawn19 = Spawn19 + Spawn20;
	}

	//Octava linea
	FVector Spawn21(-35.0f, 0.0f, 265.0f);
	FVector Spawn22(70.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 2; i++) {
		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn21, FRotator::ZeroRotator);

		Spawn21 = Spawn21 + Spawn22;
	}

	//Novena linea
	FVector Spawn23(-90.0f, 0.0f, 230.0f);
	FVector Spawn24(30.0f, 0.0f, 0.0f);

	for (int i = 1; i <= 7; i++) {
		BrickDouble = GetWorld()->SpawnActor<ABrickDoubleHit>(ABrickDoubleHit::StaticClass(), Spawn23, FRotator::ZeroRotator);

		Spawn23 = Spawn23 + Spawn24;
	}

	
}


