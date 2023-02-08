// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Brick.h"
#include "BrickDoubleHit.h"
#include "BrickShot.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABomba::ABomba()
{
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
		Movement->InitialSpeed = 100.f;
		Movement->MaxSpeed = 100.f;
		Movement->bRotationFollowsVelocity = true;
		Movement->bShouldBounce = false;
		Movement->ProjectileGravityScale = 0.0f;

		InitialLifeSpan = 5.0f;

//Cambios para el examen de invierno
		//=======================================================
		//Creamos un Trray de instancias que almacena la cantidad de instancias
		TArray<AActor*> Instances;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(),ABomba::StaticClass(), Instances);
		//Tomamos el numero de instancias de la clase bomba y si es mayor a 1 este se destruye
		if (Instances.Num() > 1)
		{
			//If exist at least one of them, set the instance with the first found one
			Instance = Cast<ABomba>(Instances[0]); //Casteamos la bomba almacenada en el Trraya para obtener su nombre y mostrarlo en pantalla
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s already exists"), *Instance->GetName()));
			//Entonces se destruye el Actor
			Destroy();
		}
	}
}

	// Called when the game starts or when spawned
	void ABomba::BeginPlay()
	{
		Super::BeginPlay();

	}

	void ABomba::NotifyActorBeginOverlap(AActor * OtherActor)
	{
		Super::NotifyActorBeginOverlap(OtherActor);
	
		//Casteamos el otheractor a un brick y si este existe hacemos lo siguiente
		ABrick* Brick = Cast<ABrick>(OtherActor);
		if (Brick) {
	
			//Destruimos el brick
			Brick->DestroyBrick();
			//Ocultamos la bomba en juego
			SetActorHiddenInGame(true);
			//Establecemos la velocidad de la bomba en cero
			Movement->StopMovementImmediately();
			//Agrandamos la caja de colision de la bomba para dar el efecto de explosion
			Collision->SetCapsuleRadius(100.0f);
			//llamamos a esta funcion para que se autodestruya
			this->TimerExplition();

		}

		ABrickDoubleHit* DoubleHit = Cast<ABrickDoubleHit>(OtherActor);
		if (DoubleHit) {
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
	void ABomba::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);

		if (GetActorLocation().Z >= 450.0f) {
			this->Destroy();
		}

	}
	//Esta funcion es un temporizador para que se destruya la bomba
	void ABomba::TimerExplition()
	{
		//
		GetWorldTimerManager().SetTimer(BombaTimerHandle, this, &ABomba::DestroyBomba, 0.3f, true, 2.0f);//cada cierto tiempo creamos una NaveAcuatica extra en el mapa con el SpawnNave
	}

	void ABomba::DestroyBomba()
	{
		//Aqui se autodestruye
		this->Destroy();
	}
