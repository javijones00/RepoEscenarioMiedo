// Fill out your copyright notice in the Description page of Project Settings.


#include "Getable.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AGetable::AGetable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	GetableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	GetableMesh->SetupAttachment(BoxComponent);

}

// Called when the game starts or when spawned
void AGetable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGetable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGetable::GetableGot()
{
	UE_LOG(LogTemp,Warning,TEXT("AGETABLE GETADO POR EL GETEBLEADOR"));
	// this->Destroy();
}


