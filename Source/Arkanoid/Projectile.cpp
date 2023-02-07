// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Brick.h"
#include "BrickDoubleHit.h"
#include "BrickShot.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Projectile.SM_Projectile'"));
	

	Projectile = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Projectile->SetStaticMesh(ProjectileMesh.Object);
	SetRootComponent(Projectile);

	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	Collision->SetCapsuleHalfHeight(15.0f);
	Collision->SetCapsuleRadius(10.0f);
	Collision->SetupAttachment(GetRootComponent());

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Projectile;
	Movement->InitialSpeed = 500.f;
	Movement->MaxSpeed = 500.f;
	Movement->bRotationFollowsVelocity = true;
	Movement->bShouldBounce = false;
	Movement->ProjectileGravityScale = 0.0f;

	InitialLifeSpan = 5.0f;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ABrick* Brick = Cast<ABrick>(OtherActor);
	if (Brick) {
		this->Destroy();
		Brick->DestroyBrick();
	}

	ABrickDoubleHit* DoubleHit = Cast<ABrickDoubleHit>(OtherActor);
	if (DoubleHit) {
		this->Destroy();
		DoubleHit->DestroyBrickDoubleHit();
		Brick->ContBricksLevel(1);
	}

	ABrickShot* Shot = Cast<ABrickShot>(OtherActor);
	if (Shot) {
		this->Destroy();
		Shot->DestroyBrickShot();
		Brick->ContBricksLevel(1);
	}
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Z >= 450.0f) {
		this->Destroy();
	}
	
}

