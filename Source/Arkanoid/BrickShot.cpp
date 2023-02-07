// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickShot.h"
#include "Kismet/GameplayStatics.h"
#include "Ball.h"
#include "Brick.h"
#include "Projectile.h"
#include "ProjectileEnemy.h"
#include "Paddle.h"

ABrickShot::ABrickShot()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBrickShot(TEXT("Material'/Game/Assets/Materials/M_BrickShot.M_BrickShot'"));
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("SoundWave'/Game/Maps/Menu/Sound/Disparo.Disparo'"));

	SM_BrickShield->SetMaterial(0, MaterialBrickShot.Object);
	SM_BrickShield->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));

	FireSound = FireAudio.Object;

	ShootTime = 0;
	TimeToSpawnShoot = 3.0f;
	Projectile = FVector(0.0f, 0.0f, 0.0f);
}

void ABrickShot::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ABrick* Brick = Cast<ABrick>(OtherActor);

	if (OtherActor->ActorHasTag("Ball") || OtherActor->ActorHasTag("Two") || OtherActor->ActorHasTag("Three")) {

		if (BounceSound != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(this, BounceSound, GetActorLocation());
		}

		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		HitBrick = HitBrick + 1;

	}

	if (HitBrick == 1) {
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrickShot::DestroyBrickShot, 0.1f, false);
		Brick->ContBricksLevel(1);
	}


}

void ABrickShot::DestroyBrickShot()
{
	this->Destroy();

	int RandScore = FMath::RandRange(1, 5);
	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->ScoreGame(RandScore);
}

void ABrickShot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ShootTime = ShootTime + DeltaTime;
	if (ShootTime >= TimeToSpawnShoot) {

		ShootTime = 0.0f;

		//Direccion del primer proyectil
		const FVector FireProjectile = FVector(0.0f, 0.0f, -10.0f);
		const FRotator FireRotationProjectile = FireProjectile.Rotation();
		const FVector Spawn = GetActorLocation();
		const FVector SpawnProjectile = Spawn + FireRotationProjectile.RotateVector(Projectile);

		UWorld* const World = GetWorld();
		if (World != nullptr) {
			World->SpawnActor<AProjectileEnemy>(SpawnProjectile, FireRotationProjectile);

			if (FireSound != nullptr) {
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}
		}

	}
}
