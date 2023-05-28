// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTerrorConfiguration.h"
#include "AudioTerrorConfiguration.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API AAudioTerrorConfiguration : public ABaseTerrorConfiguration
{
	GENERATED_BODY()

private:

	UPROPERTY(BlueprintReadOnly,  meta = (AllowPrivateAccess = "true"))
	bool IsActivated;

	//Sonidos disponibles
	UPROPERTY(EditAnywhere,Category="Sounds")
	class UAudioComponent* MyAudioComponent;
	UPROPERTY(EditAnywhere,Category="Sounds")
	TArray<class USoundBase*> SceneSounds;
	UPROPERTY(EditAnywhere,Category="Sounds")
	class USoundBase* AmbientMusic;
	UPROPERTY(EditAnywhere,Category="RandomSounds")
	TArray<AActor*> RandomTargetLocations;



    TMap<FString,USoundBase*> SoundDictionary;
	float CurrentTimeSound;
	float NextTimeSound;
	const float MaxTimeSound = 2;
	const float MinTimeSound = 10; 

	TArray<FString> RandomSounds = {"brokenBottle", "childWhispers", "ghostWhispers", "knockingAtDoor","oldTV", "screamingGhost"};

protected:

	virtual void BeginPlay() override;

	virtual void PerformChanges() override;

	virtual void Config(bool Activated) override;

public:

	AAudioTerrorConfiguration();
	
	void PlaySound(FString SoundName, FVector location);

	UFUNCTION(BlueprintCallable)
	void PlaySpawnedSound(FString SoundName, UAudioComponent* AudioComponent);

	UFUNCTION(BlueprintCallable)
	void StopSpawnedSound( UAudioComponent* AudioComponent);

	virtual void Tick(float DeltaTime) override;

};
