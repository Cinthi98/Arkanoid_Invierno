// Fill out your copyright notice in the Description page of Project Settings.


#include "HelpCapsules.h"
#include "ElongationCapsule.h"
#include "HealthCapsule.h"
#include "ShotCapsule.h"
#include "ThreeBallCapsule.h"
#include "TwoBallCapsule.h"
#include "CapsuleReinforcedBricks.h"

ABasicCapsule* AHelpCapsules::CreateCapsule(int NumCapsule, FVector Location)
{
    FVector Spawn2(0.0f, 0.0f, -22.0f);

    if (NumCapsule == 1) {  
        return GetWorld()->SpawnActor<AElongationCapsule>(Location + Spawn2, FRotator::ZeroRotator);
    }
    else if (NumCapsule == 2) {
        return GetWorld()->SpawnActor<AHealthCapsule>(Location + Spawn2, FRotator::ZeroRotator);
    }
    else if (NumCapsule == 3) { 
        return GetWorld()->SpawnActor<AShotCapsule>(Location + Spawn2, FRotator::ZeroRotator);
    }
    else if (NumCapsule == 4) {
        return GetWorld()->SpawnActor<AThreeBallCapsule>(Location + Spawn2, FRotator::ZeroRotator);
    }
    else if (NumCapsule == 5) { 
        return GetWorld()->SpawnActor<ATwoBallCapsule>(Location + Spawn2, FRotator::ZeroRotator);
    }
    else if (NumCapsule == 6) {
        return GetWorld()->SpawnActor<ACapsuleReinforcedBricks>(Location + Spawn2, FRotator::ZeroRotator);
    }
    else return nullptr; //Devuelve nada si el nombre de la capsula no existe
}
