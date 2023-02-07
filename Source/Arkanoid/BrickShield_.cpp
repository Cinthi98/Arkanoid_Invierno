// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickShield_.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Ball.h"

// Sets default values
ABrickShield_::ABrickShield_()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickShieldMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Brick.SM_Brick'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialShield(TEXT("Material'/Game/Assets/Materials/ColorRandom.ColorRandom'"));
	static ConstructorHelpers::FObjectFinder<USoundBase> BounceAudio(TEXT("SoundWave'/Game/Maps/Menu/Sound/Bounce.Bounce'"));

	SM_BrickShield = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_BrickShield->SetRelativeScale3D(FVector(7.25f, 1.0f, 1.0f));
	SM_BrickShield->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_BrickShield->SetStaticMesh(BrickShieldMesh.Object);
	SM_BrickShield->SetMaterial(0, MaterialShield.Object);
	SetRootComponent(SM_BrickShield);

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Collision->SetBoxExtent(FVector(25.5f, 12.0f, 12.0f));
	Collision->SetupAttachment(GetRootComponent());

	BounceSound = BounceAudio.Object;

	if (MaterialShield.Object != NULL) {
		_Dynamic = (UMaterial*)MaterialShield.Object;
	}

}

// Called when the game starts or when spawned
void ABrickShield_::BeginPlay()
{
	Super::BeginPlay();
	
	if (_Dynamic) {
		MaterialInstance = UMaterialInstanceDynamic::Create(_Dynamic, this);
	}

	if (MaterialInstance) {
		SM_BrickShield->SetMaterial(0, MaterialInstance);
	}

	ChangeColor();

}

void ABrickShield_::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Ball") || OtherActor->ActorHasTag("Two") || OtherActor->ActorHasTag("Three")) {

		if (BounceSound != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(this, BounceSound, GetActorLocation());
		}

		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

	}

}

void ABrickShield_::ChangeColor()
{
	MaterialInstance->SetVectorParameterValue("RandomColor", FLinearColor(UKismetMathLibrary::RandomFloatInRange(0.0f, 1.00f), UKismetMathLibrary::RandomFloatInRange(0.0f, 1.00f), UKismetMathLibrary::RandomFloatInRange(0.0f, 1.00f)));
}

void ABrickShield_::DestroyBrick()
{
	this->Destroy();
}

// Called every frame
void ABrickShield_::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

