// Fill out your copyright notice in the Description page of Project Settings.
#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Paddle_PlayerController.h"
#include "Projectile.h"
#include "BasicCapsule.h"
#include "LevelBricks.h"
#include "Ball.h"
#include "TwoBall.h"
#include "ThreeBallCapsule.h"
#include "ShotCapsule.h"
#include "Brick.h"
#include "BrickShield_.h"

// Sets default values
APaddle::APaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PaddleMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Paddle.SM_Paddle'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialPaddle(TEXT("Material'/Game/Assets/Materials/M_Paddle.M_Paddle'"));
	static ConstructorHelpers::FObjectFinder<USoundBase> BounceAudio(TEXT("SoundWave'/Game/Maps/Menu/Sound/Bounce.Bounce'"));
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("SoundWave'/Game/Maps/Menu/Sound/Disparo.Disparo'"));

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Paddle"));
	SM_Paddle->SetStaticMesh(PaddleMesh.Object);
	SM_Paddle->SetMaterial(0, MaterialPaddle.Object);
	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhysiscActor"));
	SetRootComponent(SM_Paddle);

	PaddleCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	PaddleCollision->SetupAttachment(GetRootComponent());

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	FloatingMovement->MaxSpeed = 3000.0f;
	FloatingMovement->Acceleration = 2500.0f;
	FloatingMovement->Deceleration = 2500.0f;

	FireSound = FireAudio.Object;
	BounceSound = BounceAudio.Object;

	ShootTime = 0;
	TimeToSpawnShoot = 1.0f;
	Projectile = FVector(0.0f, 0.0f, 0.0f);

	LifeTime = 3;
	Level = 1;
	GameOver = 0;
	Winner = 0;
	Score = 0;
	CheckWinner = true;
	Disparo = true;
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	SM_Paddle->OnComponentBeginOverlap.AddDynamic(this, &APaddle::OnOverlapBeginPaddle);
}

void APaddle::OnOverlapBeginPaddle(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABall* Ball = Cast<ABall>(OtherActor);
	if (OtherActor->ActorHasTag("Ball")) {
		if (BounceSound != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(this, BounceSound, GetActorLocation());
		}
	}

	ABasicCapsule* Capsule = Cast<ABasicCapsule>(OtherActor);
	if (Capsule)
	{
		Capsule->Destroy();

		//Capsulas de ayuda
		if (Capsule->GetIntCapsuleHelps() == 4) { // Capsule de Three Ball
			Controller = Cast<APaddle_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
			Controller->SpawnThreeBall();
			Controller->LaunchThree();
		}

		if (Capsule->GetIntCapsuleHelps() == 1) { // Capsule de elongation
			SM_Paddle->SetRelativeScale3D(FVector(1.5f, 1.0f, 1.0f));
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::NormalScale, 5.0f, false);
		}

		if (Capsule->GetIntCapsuleHelps() == 5) { // Capsule de two ball
			Controller = Cast<APaddle_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
			Controller->SpawnTwoBall();
			Controller->LaunchTwo();
		}

		if (Capsule->GetIntCapsuleHelps() == 3) { // Capsule Shot
			SM_Paddle->SetRelativeScale3D(FVector(1.5f, 1.0f, 1.0f));
			Disparo = true;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::NormalFire, 10.0f, false);
		}

		if (Capsule->GetIntCapsuleHelps() == 2) { //Capsule Health
			IncreaseOfLife(1);
		}

		if (Capsule->GetIntCapsuleHelps() == 6) { //Bricks reforzados
			FVector LocationCapsule(0.0f, 0.0f, 60.0f);
			Reinforced = GetWorld()->SpawnActor<ABrickShield_>(LocationCapsule, FRotator::ZeroRotator);
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::DestroyReinforced, 5.0f, false);
		}

		//Capsulas de antiayuda
		if (Capsule->GetCapsuleNameAntiHelps() == "AHealth") {
			DecreaseOfLife(1);
		}

		if (Capsule->GetCapsuleNameAntiHelps() == "Destroy") {
			Controller = Cast<APaddle_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
			Controller->DestroyBall();
			Controller->SpawnNewBall();
			DecreaseOfLife(1);
		}

		if (Capsule->GetCapsuleNameAntiHelps() == "Short") {
			Disparo = false;
			SM_Paddle->SetRelativeScale3D(FVector(0.5f, 1.0f, 1.0f));
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::NormalScale, 5.0f, false);
		}

		if (Capsule->GetCapsuleNameAntiHelps() == "Speed") {
			FloatingMovement->MaxSpeed = 3500.0f;
			FloatingMovement->Acceleration = 3500.0f;
			FloatingMovement->Deceleration = 0.0f;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::NormalVelocity, 5.0f, false);
		}

		if (Capsule->GetCapsuleNameAntiHelps() == "Static") {
			FloatingMovement->Acceleration = 0.0f;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &APaddle::NormalVelocity, 3.0f, false);
		}
	}

}

void APaddle::NormalScale()
{
	SM_Paddle->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void APaddle::NormalVelocity()
{
	FloatingMovement->MaxSpeed = 3000.0f;
	FloatingMovement->Acceleration = 2500.0f;
	FloatingMovement->Deceleration = 2500.0f;
}

void APaddle::NormalFire()
{
	Disparo = false;
	SM_Paddle->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void APaddle::DestroyReinforced()
{
	Reinforced->Destroy();
}

void APaddle::LevelUp(int Up)
{
	Level = Level + Up;
}

void APaddle::IncreaseOfLife(int life)
{
	LifeTime = LifeTime + life;
}

void APaddle::DecreaseOfLife(int life)
{
	LifeTime = LifeTime - life;
}

void APaddle::RestoreLevel(int _Level)
{
	Level = _Level;
}

void APaddle::RestoreGameOver(int RestoreGameOver)
{
	GameOver = RestoreGameOver;
}

void APaddle::RestoreWinner(bool RestoreWinner)
{
	CheckWinner = RestoreWinner;
}

void APaddle::ScoreGame(int _Score)
{
	Score = Score + _Score;
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Disparo == true) {

		ShootTime = ShootTime + DeltaTime;
		if (ShootTime >= TimeToSpawnShoot) {

			ShootTime = 0.0f;

			//Direccion del primer proyectil
			const FVector FireProjectile1 = FVector(0.0f, 0.0f, 400.0f);
			const FRotator FireRotationProjectile1 = FireProjectile1.Rotation();
			const FVector Spawn1 = GetActorLocation() + FVector(-40.0f, 0.0f, 10.0f);
			const FVector SpawnProjectile1 = Spawn1 + FireRotationProjectile1.RotateVector(Projectile);
			//Direccion del segundo proyectil
			const FVector FireProjectile2 = FVector(0.0f, 0.0f, 400.0f);
			const FRotator FireRotationProjectile2 = FireProjectile2.Rotation();
			const FVector Spawn2 = GetActorLocation() + FVector(40.0f, 0.0f, 10.0f);
			const FVector SpawnProjectile2 = Spawn2 + FireRotationProjectile2.RotateVector(Projectile);

			UWorld* const World = GetWorld();
			if (World != nullptr) {
				World->SpawnActor<AProjectile>(SpawnProjectile1, FireRotationProjectile1);
				World->SpawnActor<AProjectile>(SpawnProjectile2, FireRotationProjectile2);

				if (FireSound != nullptr) {
					UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
				}
			}

		}
	}

	if (GetLifeTime() == 0) {
		GameOver = 1;
		LifeTime = 3;
		Level = 1;
	}

	if (Brick->GetBricksLevel() == 0 && CheckWinner == true) {
		LevelUp(1);
		CheckWinner = false;
	}

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::MoveHorizontal(float _AxisValue)
{
	AddMovementInput(FVector(_AxisValue, 0.0f, 0.0f), 1.0f, false);
}
