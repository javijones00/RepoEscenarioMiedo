// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTerrorConfiguration.h"
#include "VisibilityTerrorConfiguration.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API AVisibilityTerrorConfiguration : public ABaseTerrorConfiguration
{
	GENERATED_BODY()

protected:
	//virtual void PerformChanges() override;

	UPROPERTY(EditAnywhere)
	class APostProcessVolume* PostProcessVolume;

	UPROPERTY(EditAnywhere)
	class AExponentialHeightFog* ExponentialHeightFog;
	
public:

	virtual void PerformChanges() override;

	virtual void Config(bool Activated) override;
};
	

