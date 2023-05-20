// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTerrorConfiguration.h"
#include "MonsterTerrorConfiguration.generated.h"
/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API AMonsterTerrorConfiguration : public ABaseTerrorConfiguration
{
	GENERATED_BODY()

private:
	
	UPROPERTY(EditAnywhere, Category="Monster Reference", meta = (AllowPrivateAccess = "true"))
	class ACharacter* MonsterReference;
	UPROPERTY(EditAnywhere, Category="Monster Reference", meta = (AllowPrivateAccess = "true"))
	float TimeUntilChasing = 60;

	FTimerHandle ChasingHandle;



	void StartChasingInvoked();

protected:
	virtual void PerformChanges() override;
};
