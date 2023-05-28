// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SandboxOptions.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API USandboxOptions : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Configurations", meta = (AllowPrivateAccess = "true"))
	class AAudioTerrorConfiguration* AudioConfig;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Configurations", meta = (AllowPrivateAccess = "true"))
	class AIluminationTerrorConfiguration* IlumConfig;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Configurations", meta = (AllowPrivateAccess = "true"))
	class APostProcessTerrorConfig* PPConfig;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Configurations", meta = (AllowPrivateAccess = "true"))
	class AVisibilityTerrorConfiguration* VisibilityConfig;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Configurations", meta = (AllowPrivateAccess = "true"))
	class AMonsterTerrorConfiguration* MonsterConfig;


public:

    void SetConfigurations(	class AAudioTerrorConfiguration* AudioConfig,class AIluminationTerrorConfiguration* IlumConfig,class APostProcessTerrorConfig* PPConfig,class AVisibilityTerrorConfiguration* VisibilityConfig,class AMonsterTerrorConfiguration* MonsterConfig);
	UFUNCTION(BlueprintCallable)
	void ConfigureLight(bool Activated);
	UFUNCTION(BlueprintCallable)
	void ConfigurePP(bool Activated);
	UFUNCTION(BlueprintCallable)
	void ConfigureAudio(bool Activated);
	UFUNCTION(BlueprintCallable)
	void ConfigureVisibility(bool Activated);
	UFUNCTION(BlueprintCallable)
	void ConfigureMonster(bool Activated);

};
