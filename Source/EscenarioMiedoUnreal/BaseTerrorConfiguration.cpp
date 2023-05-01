// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTerrorConfiguration.h"

// Sets default values
ABaseTerrorConfiguration::ABaseTerrorConfiguration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseTerrorConfiguration::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseTerrorConfiguration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseTerrorConfiguration::PerformChanges()
{
	UE_LOG(LogTemp,Warning,TEXT("Changes performed"));
}

void ABaseTerrorConfiguration::Config()
{
	//Ignorar por ahora
}

