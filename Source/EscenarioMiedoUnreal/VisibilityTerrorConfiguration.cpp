// Fill out your copyright notice in the Description page of Project Settings.


#include "VisibilityTerrorConfiguration.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/PostProcessVolume.h"



void AVisibilityTerrorConfiguration::PerformChanges()
{
    ExponentialHeightFog->SetActorHiddenInGame(false);
    PostProcessVolume->Settings.VignetteIntensity= 0.544f;

   UE_LOG(LogTemp, Warning, TEXT("Hello"));

}
