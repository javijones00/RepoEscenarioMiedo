// Fill out your copyright notice in the Description page of Project Settings.


#include "RaycastAgent.h"
#include "DrawDebugHelpers.h"
#include "Getable.h"

// Sets default values for this component's properties
URaycastAgent::URaycastAgent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void URaycastAgent::BeginPlay()
{
	Super::BeginPlay();

	CurrentWorld = GetWorld();
	GrabberShape = FCollisionShape::MakeSphere(GrabberRadious);
	
}


// Called every frame
void URaycastAgent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(GetAvailableGetable())
	{
		CurrentGetable->ShowPress(true);
	}
	else
	{
		if(CurrentGetable)
		{
			CurrentGetable->ShowPress(false);
		}
		CurrentGetable = nullptr;
	}

}

void URaycastAgent::Grab()
{
	if(CurrentGetable)
	{
		OnGetable(CurrentGetable);
	}
}

bool URaycastAgent::GetAvailableGetable()
{
	FVector InitialVector = GetComponentLocation();
	FVector FinalVector = GetForwardVector()*RaycastDistance + InitialVector;
	FHitResult HitResult;

	bool success = CurrentWorld->SweepSingleByChannel(HitResult,InitialVector,FinalVector,FQuat::Identity,ECollisionChannel::ECC_GameTraceChannel1,GrabberShape);
	
	if(success)
	{
		if(HitResult.GetActor()->GetClass()->IsChildOf<AGetable>() && !HitResult.GetActor()->IsHidden())
		{
			CurrentGetable = Cast<AGetable>(HitResult.GetActor());
			return true;
		}
		
	}
	return false;
}

void URaycastAgent::OnGetable(AGetable* Getable)
{
	Getable->GetableGot();
}


