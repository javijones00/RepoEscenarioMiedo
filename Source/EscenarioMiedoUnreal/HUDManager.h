// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUDManager.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API AHUDManager : public AActor
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditAnywhere, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UNoteWidget> MyNoteWidget;
	UPROPERTY(EditAnywhere, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> PressWidget;
	UPROPERTY(EditAnywhere, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UNewNoteWidget> NewNoteWidget;
	UPROPERTY(EditAnywhere, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class USandboxOptions> SandboxWidget;

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

	class UNewNoteWidget* CurrentNewNoteWidget;
	class UNoteWidget* CurrentNoteWidget;
	class UUserWidget* CurrentPressWidget;
	UPROPERTY(BlueprintReadOnly, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	class USandboxOptions* CurrentSandbox;
	class APlayerController* CurrentPC;

	virtual void BeginPlay() override;

	FTimerHandle NewNoteHandle;

public:

	void CreateNoteUI(FText noteText,  class ABaseTerrorConfiguration* CurrentTerror, class AGetableNote* NextNote, class UAudioComponent* NoteSound);

	void ShowPress(bool value);

	UFUNCTION(BlueprintCallable)
	void NewNote();
	UFUNCTION(BlueprintCallable)
	void ShowSandBox(bool value);
	UFUNCTION(BlueprintCallable)
	void ShowHideSandBox();

	void HideNewNote();

	UFUNCTION(BlueprintCallable)
	void EnableCursor(bool value);
	UFUNCTION(BlueprintImplementableEvent)
	void EndedBeginPlay();
	
};
