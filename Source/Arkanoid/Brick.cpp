// Fill out your copyright notice in the Description page of Project Settings.

#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine.h"
#include "Paddle.h"
#include "Ball.h"
#include "TwoBall.h"
#include "ThreeBall.h"
#include "Bomba.h"
#include "HelpCapsules.h"

static int BricksLevel = 70;

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Brick.SM_Brick'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialMesh(TEXT("Material'/Game/Assets/Materials/ColorRandom.ColorRandom'"));
	static ConstructorHelpers::FObjectFinder<USoundBase> BounceAudio(TEXT("SoundWave'/Game/Maps/Menu/Sound/Bounce.Bounce'"));

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetStaticMesh(BrickMesh.Object);
	SetRootComponent(SM_Brick);

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Collision->SetBoxExtent(FVector(25.5f, 12.0f, 12.0f));
	Collision->SetupAttachment(GetRootComponent());

	BounceSound = BounceAudio.Object;

	if (MaterialMesh.Object != NULL) {
		_Dynamic = (UMaterial*)MaterialMesh.Object;
	}

	HabilitadoCreacionCapsulas = false;

}

void ABrick::ContBricksLevel(int _Cont)
{
	BricksLevel = BricksLevel - _Cont;
}

void ABrick::RestoreLevel(int Restore)
{
	BricksLevel = Restore;
}

int ABrick::GetBricksLevel()
{
	return BricksLevel;
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	if (_Dynamic) {
		MaterialInstance = UMaterialInstanceDynamic::Create(_Dynamic, this);
	}

	if (MaterialInstance) {
		SM_Brick->SetMaterial(0, MaterialInstance);
	}

	ChangeColor();

}

void ABrick::ChangeColor()
{
	MaterialInstance->SetVectorParameterValue("RandomColor", FLinearColor(UKismetMathLibrary::RandomFloatInRange(0.0f, 1.00f), UKismetMathLibrary::RandomFloatInRange(0.0f, 1.00f), UKismetMathLibrary::RandomFloatInRange(0.0f, 1.00f)));
}

//Cambios para el examen de invierno

void ABrick::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//Se agregó la condición para que los brick desaparezcan al interactuar con la bomba
	if (OtherActor->ActorHasTag("Ball") || OtherActor->ActorHasTag("Two") || OtherActor->ActorHasTag("Three") || OtherActor->ActorHasTag("Bomba")) {

		if (BounceSound != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(this, BounceSound, GetActorLocation());
		}

		ABall* MyBall = Cast<ABall>(OtherActor);
		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);
		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);

		if (HabilitadoCreacionCapsulas == true) {
			FVector GetLocation = this->GetActorLocation();
			CreateCapsule(GetLocation);
		}
		
	}
}

void ABrick::CreateCapsule(FVector Location)
{
	int RandCapsules = FMath::RandRange(1, 6);
	ABrick* CapsuleCreator = GetWorld()->SpawnActor<AHelpCapsules>(AHelpCapsules::StaticClass(), FVector(0.0f, 0.0f, -100.0f), FRotator::ZeroRotator);
	ABasicCapsule* Capsule = CapsuleCreator->OrdenCapsule(RandCapsules, Location);
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	HabilitadoCreacionCapsulas = FMath::FRandRange(0, 9) <= 4 ? true : false;

}

void ABrick::DestroyBrick()
{
	ContBricksLevel(1);
	this->Destroy();

	int RandScore = FMath::RandRange(1, 5);
	APaddle* Paddle = Cast<APaddle>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Paddle->ScoreGame(RandScore);

}

ABasicCapsule* ABrick::OrdenCapsule(int NumCategory, FVector Spawn)
{
	ABasicCapsule* Capsules = CreateCapsule(NumCategory, Spawn);
	return Capsules;
}

ABasicCapsule* OrdenCapsule(int NumCategory, FVector Spawn)
{
	return nullptr;
}


