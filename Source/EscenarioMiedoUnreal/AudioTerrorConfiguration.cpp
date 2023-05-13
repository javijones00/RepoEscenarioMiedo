// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioTerrorConfiguration.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

void AAudioTerrorConfiguration::BeginPlay()
{
    Super::BeginPlay();
    for(int i = 0; i<SceneSounds.Num();i++)
    {
        SoundDictionary.Add(SceneSounds[i]->GetName(),SceneSounds[i]);
       
    }
}

void AAudioTerrorConfiguration::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(IsActivated)
    {
        CurrentTimeSound += DeltaTime;
        if(CurrentTimeSound >= NextTimeSound)
        {
            FString soundToPlay = RandomSounds[FMath::RandRange(0,RandomSounds.Num())];
            FVector location = RandomTargetLocations[FMath::RandRange(0,RandomTargetLocations.Num())]->GetActorLocation();
            PlaySound(soundToPlay,location);
            NextTimeSound = FMath::RandRange(MinTimeSound, MaxTimeSound);
        }
    }
}

void AAudioTerrorConfiguration::PerformChanges()
{
    IsActivated = true;
    UGameplayStatics::PlaySound2D(GetWorld(),AmbientMusic);
      UE_LOG(LogTemp, Warning, TEXT("Performed audio"));
}

void AAudioTerrorConfiguration::PlaySound(FString SoundName,FVector Location)
{
    if(IsActivated)
    {
        USoundBase* soundRef =SoundDictionary.FindRef(SoundName);
        if(soundRef)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(),soundRef,Location);
        }
    }
}

