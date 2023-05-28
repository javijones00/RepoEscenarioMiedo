// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxOptions.h"
#include "AudioTerrorConfiguration.h"
#include "IluminationTerrorConfiguration.h"
#include "MonsterTerrorConfiguration.h"
#include "VisibilityTerrorConfiguration.h"
#include "PostProcessTerrorConfig.h"

void USandboxOptions::SetConfigurations(AAudioTerrorConfiguration *audioConfig, AIluminationTerrorConfiguration *ilumConfig, APostProcessTerrorConfig *ppConfig, AVisibilityTerrorConfiguration *visibilityConfig, AMonsterTerrorConfiguration *monsterConfig)
{
    AudioConfig = audioConfig;
    IlumConfig = ilumConfig;
    PPConfig = ppConfig;
    VisibilityConfig = visibilityConfig;
    MonsterConfig = monsterConfig;
}

void USandboxOptions::ConfigureLight(bool Activated)
{
    IlumConfig->Config(Activated);
}

void USandboxOptions::ConfigurePP(bool Activated)
{
    PPConfig->Config(Activated);
}

void USandboxOptions::ConfigureAudio(bool Activated)
{
    AudioConfig->Config(Activated);
}

void USandboxOptions::ConfigureVisibility(bool Activated)
{
    VisibilityConfig->Config(Activated);
}

void USandboxOptions::ConfigureMonster(bool Activated)
{
    MonsterConfig->Config(Activated);
}
