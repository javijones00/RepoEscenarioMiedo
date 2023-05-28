// Fill out your copyright notice in the Description page of Project Settings.


#include "IluminationTerrorConfiguration.h"
#include "Engine/Light.h"



 void AIluminationTerrorConfiguration::PerformChanges()
{
    for(int i = 0; i<NewSceneLights.Num();i++)
    {
        NewSceneLights[i]->SetActorHiddenInGame(false);
    }
     for(int i = 0; i<OldSceneLights.Num();i++)
    {
        OldSceneLights[i]->SetActorHiddenInGame(true);
    }

    
}
void AIluminationTerrorConfiguration::Config(bool Activated)
{
     for(int i = 0; i<NewSceneLights.Num();i++)
    {
        NewSceneLights[i]->SetActorHiddenInGame(!Activated);
    }
     for(int i = 0; i<OldSceneLights.Num();i++)
    {
        OldSceneLights[i]->SetActorHiddenInGame(Activated);
    }
}
