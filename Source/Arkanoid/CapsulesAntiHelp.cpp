// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulesAntiHelp.h"
#include "CapsuleAntiHealth.h"
#include "CapsuleDestroyBall.h"
#include "CapsulePaddleShort.h"
#include "CapsulePaddleSpeed.h"
#include "CapsulePaddleStatic.h"

ABasicCapsule* ACapsulesAntiHelp::CreateCapsule(FString NameCapsule)
{
    float Random = FMath::RandRange(-150, 150);

    FVector Spawn(Random, 0.0f, 520.0f);

    if (NameCapsule.Equals("AHealth")) { 
        return GetWorld()->SpawnActor<ACapsuleAntiHealth>(Spawn, FRotator::ZeroRotator);
    }
    else if (NameCapsule.Equals("Destroy")) { 
        return GetWorld()->SpawnActor<ACapsuleDestroyBall>(Spawn, FRotator::ZeroRotator);
    }
    else if (NameCapsule.Equals("Short")) {  
        return GetWorld()->SpawnActor<ACapsulePaddleShort>(Spawn, FRotator::ZeroRotator);
    }
    else if (NameCapsule.Equals("Speed")) { 
        return GetWorld()->SpawnActor<ACapsulePaddleSpeed>(Spawn, FRotator::ZeroRotator);
    }
    else if (NameCapsule.Equals("Static")) { 
        return GetWorld()->SpawnActor<ACapsulePaddleStatic>(Spawn, FRotator::ZeroRotator);
    }
    else return nullptr; //Devuelve nada si el nombre de la capsula no existe
}
