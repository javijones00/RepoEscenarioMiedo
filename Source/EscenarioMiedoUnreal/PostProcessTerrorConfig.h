// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTerrorConfiguration.h"
#include "PostProcessTerrorConfig.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API APostProcessTerrorConfig : public ABaseTerrorConfiguration
{
	GENERATED_BODY()
	
	
protected:
	//virtual void PerformChanges() override;

	UPROPERTY(EditAnywhere)
	class APostProcessVolume* PostProcessVolume;

public:

	virtual void PerformChanges() override;

	virtual void Config(bool Activated) override;
};
