// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCapsule.h"
#include "Paddle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABasicCapsule::ABasicCapsule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("StaticMesh'/Game/Assets/Meshes/Capsule.Capsule'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialCapsule(TEXT("Material'/Game/Assets/Materials/CapsuleHelp.CapsuleHelp'"));

	SM_BasicCapsule = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BasicCapsule"));
	SM_BasicCapsule->SetStaticMesh(CapsuleMesh.Object);
	SM_BasicCapsule->SetMaterial(0, MaterialCapsule.Object);
	SetRootComponent(SM_BasicCapsule);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(12.f, 12.f, 12.f));
	BoxCollision->SetHiddenInGame(true);
	BoxCollision->SetupAttachment(GetRootComponent());
	

	x = 1.0f;
	vc = 25;

}


// Called when the game starts or when spawned
void ABasicCapsule::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentHit.AddDynamic(this, &ABasicCapsule::ComponentHit);
	
}

void ABasicCapsule::ComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("La Capsula tuvo un hit")));


}

// Called every frame
void ABasicCapsule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Creo la direccion y el vector movimiento
	const FVector MoveDirection = FVector(0.0f, 0.0f, -x);
	const FVector Movement = MoveDirection * vc * DeltaTime;

	if (Movement.SizeSquared() > 0.0f)
	{
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, FRotator::ZeroRotator, false, &Hit);

		if (GetActorLocation().Z <= -20.0f) {
			this->Destroy();
		}
	}
}




