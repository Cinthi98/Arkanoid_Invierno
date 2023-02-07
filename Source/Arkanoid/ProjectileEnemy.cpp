// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileEnemy.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Paddle.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AProjectileEnemy::AProjectileEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Projectile.SM_Projectile'"));
	

	ProjectileEnemy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	ProjectileEnemy->SetStaticMesh(ProjectileMesh.Object);
	SetRootComponent(ProjectileEnemy);

	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	Collision->SetCapsuleHalfHeight(15.0f);
	Collision->SetCapsuleRadius(10.0f);
	Collision->SetupAttachment(GetRootComponent());

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = ProjectileEnemy;
	Movement->InitialSpeed = 500.f;
	Movement->MaxSpeed = 500.f;
	Movement->bRotationFollowsVelocity = true;
	Movement->bShouldBounce = false;
	Movement->ProjectileGravityScale = 0.0f;


	InitialLifeSpan = 3.0f;

}

// Called when the game starts or when spawned
void AProjectileEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileEnemy::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	APaddle* Paddle = Cast<APaddle>(OtherActor);
	if (Paddle) {
		Paddle->DecreaseOfLife(1);
		this->Destroy();
	}
}

// Called every frame
void AProjectileEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Z <= -20.0f) {
		this->Destroy();
	}

}

