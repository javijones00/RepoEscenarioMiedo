// Fill out your copyright notice in the Description page of Project Settings.


#include "ScenarioTerrorConfig.h"

void AScenarioTerrorConfig::BeginPlay()
{
    Super::BeginPlay();
    CurrentPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();
}
 void AScenarioTerrorConfig::PerformChanges()
{
    if(CurrentPlayer)
    {
        CurrentPlayer->SetActorLocation(DestinyLocation);
    }
    
}
