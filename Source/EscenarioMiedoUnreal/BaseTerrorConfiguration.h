// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTerrorConfiguration.generated.h"

UCLASS()
class ESCENARIOMIEDOUNREAL_API ABaseTerrorConfiguration : public AActor
{
	GENERATED_BODY()
	
public:	

	ABaseTerrorConfiguration();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void PerformChanges();

	virtual void Config();

};
