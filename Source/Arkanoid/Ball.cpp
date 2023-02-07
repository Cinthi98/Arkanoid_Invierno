// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "TwoBall.h"
#include "ThreeBall.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Ball.SM_Ball'"));
	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetStaticMesh(BallMesh.Object);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhsysiscActor"));
	SetRootComponent(SM_Ball);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 0.0f;
	ProjectileMovement->MaxSpeed = 0.0f;
	ProjectileMovement->bShouldBounce = true; //Debe rebotar
	ProjectileMovement->Bounciness = 1.1f; //Rebote
	ProjectileMovement->Friction = 0.0f; //Friccion

}

void ABall::Launch()
{
	if (!BallLaunched) 
	{
		SM_Ball->AddImpulse(FVector(160.0f, 0.0f, 200.0f), FName(), true);
		BallLaunched = true;
		
	}
}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

void ABall::DestroyBall()
{
	Destroy();
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


