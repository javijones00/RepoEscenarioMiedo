// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioTerrorConfiguration.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Components/AudioComponent.h"

AAudioTerrorConfiguration::AAudioTerrorConfiguration()
{
    MyAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("MusicAudioComponent"));
    MyAudioComponent->SetupAttachment(RootComponent);

}

void AAudioTerrorConfiguration::BeginPlay()
{
    Super::BeginPlay();
    for(int i = 0; i<SceneSounds.Num();i++)
    {
        SoundDictionary.Add(SceneSounds[i]->GetName(),SceneSounds[i]);
       
    }
     NextTimeSound = FMath::RandRange(MinTimeSound, MaxTimeSound);
}

void AAudioTerrorConfiguration::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(IsActivated)
    {
        CurrentTimeSound += DeltaTime;
        if(CurrentTimeSound >= NextTimeSound)
        {
            FString soundToPlay = RandomSounds[FMath::RandRange(0,RandomSounds.Num()-1)];
            FVector location = RandomTargetLocations[FMath::RandRange(0,RandomTargetLocations.Num()-1)]->GetActorLocation();
            PlaySound(soundToPlay,location);
            NextTimeSound = FMath::RandRange(MinTimeSound, MaxTimeSound);
            CurrentTimeSound = 0;
        }
    }
}

void AAudioTerrorConfiguration::PerformChanges()
{
    IsActivated = true;
    MyAudioComponent->SetSound(AmbientMusic);
    MyAudioComponent->Play();
    UE_LOG(LogTemp, Warning, TEXT("Performed audio"));
}

void AAudioTerrorConfiguration::Config(bool Activated)
{
    IsActivated = Activated;
    if(Activated)
    {
        MyAudioComponent->SetSound(AmbientMusic);
        MyAudioComponent->Play();
    }
    else
    {
        MyAudioComponent->Stop();
    }
}

void AAudioTerrorConfiguration::PlaySound(FString SoundName,FVector Location)
{
    if(IsActivated)
    {
        USoundBase* soundRef = SoundDictionary.FindRef(SoundName);
        if(soundRef)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(),soundRef,Location);
        }
    }
}
 void AAudioTerrorConfiguration::PlaySpawnedSound(FString SoundName, UAudioComponent* AudioComponent)
 {
    if(IsActivated)
    {
        USoundBase* soundRef = SoundDictionary.FindRef(SoundName);
        if(soundRef != nullptr)
        {
            if(AudioComponent)
            {
                if(!AudioComponent->Sound.GetName().Equals(SoundName))
                {
                    AudioComponent->Sound = soundRef;
                }
                if(!AudioComponent->IsActive())
                {
                    AudioComponent->SetActive(true);
                }
            }
            
           
        }
    }
 }
void  AAudioTerrorConfiguration::StopSpawnedSound( UAudioComponent* AudioComponent)
{
    if(IsActivated)
    {
        if(AudioComponent)
        {
            AudioComponent->SetActive(false);
        }
    }
}
