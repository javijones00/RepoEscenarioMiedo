// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "RaycastAgent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCENARIOMIEDOUNREAL_API URaycastAgent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URaycastAgent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	class AGetable* CurrentGetable;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Grab();

private:

	UWorld* CurrentWorld;

	FCollisionShape GrabberShape;

	


	UPROPERTY(EditAnywhere)
	float RaycastDistance = 200.f;
	UPROPERTY(EditAnywhere)
	float GrabberRadious = 100.f;

	bool GetAvailableGetable();
	void OnGetable(class AGetable *Getable);


};
