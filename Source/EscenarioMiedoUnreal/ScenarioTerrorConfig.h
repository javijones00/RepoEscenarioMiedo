// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTerrorConfiguration.h"
#include "ScenarioTerrorConfig.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API AScenarioTerrorConfig : public ABaseTerrorConfiguration
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	virtual void PerformChanges() override;

	class APawn* CurrentPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	FVector DestinyLocation;
	
};
