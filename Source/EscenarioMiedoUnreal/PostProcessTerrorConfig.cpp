// Fill out your copyright notice in the Description page of Project Settings.


#include "PostProcessTerrorConfig.h"
#include "Engine/PostProcessVolume.h"

void APostProcessTerrorConfig::PerformChanges()
{
    PostProcessVolume->bEnabled = true;
    // PostProcessVolume->Settings.vi

}
