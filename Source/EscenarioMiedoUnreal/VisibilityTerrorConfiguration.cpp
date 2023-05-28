// Fill out your copyright notice in the Description page of Project Settings.


#include "VisibilityTerrorConfiguration.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/PostProcessVolume.h"



void AVisibilityTerrorConfiguration::PerformChanges()
{
    ExponentialHeightFog->SetActorHiddenInGame(false);
    PostProcessVolume->Settings.VignetteIntensity= 1.0f;

 

}
void AVisibilityTerrorConfiguration::Config(bool Activated)
{
    ExponentialHeightFog->SetActorHiddenInGame(!Activated);
    PostProcessVolume->Settings.VignetteIntensity= Activated? 1.0f : 0.0f;
}