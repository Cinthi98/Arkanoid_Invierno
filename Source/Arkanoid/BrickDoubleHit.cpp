// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickDoubleHit.h"
#include "Kismet/GameplayStatics.h"
#include "Ball.h"
#include "Brick.h"
#include "Projectile.h"
#include "Paddle.h"

ABrickDoubleHit::ABrickDoubleHit()
{
	SM_BrickShield->SetRelativeScale3D(FVector(0.5f, 1.0f, 1.0f));
}

void ABrickDoubleHit::NotifyActorBeginOverlap(AActor* OtherActor)
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

		ContHit = ContHit + 1;
	}

	if (ContHit == 2) {
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrickDoubleHit::DestroyBrickDoubleHit, 0.1f, false);
		Brick->ContBricksLevel(1);
	}

}

void ABrickDoubleHit::DestroyBrickDoubleHit()
{
	this->Destroy();

	int RandScore = FMath::RandRange(1, 5);
	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->ScoreGame(RandScore);
}

