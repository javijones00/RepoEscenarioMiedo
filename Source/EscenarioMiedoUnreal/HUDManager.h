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

	class UNewNoteWidget* CurrentNewNoteWidget;
	class UNoteWidget* CurrentNoteWidget;
	class UUserWidget* CurrentPressWidget;
	class APlayerController* CurrentPC;

	virtual void BeginPlay() override;

	FTimerHandle NewNoteHandle;

public:

	void CreateNoteUI(FText noteText,  class ABaseTerrorConfiguration* CurrentTerror);

	void ShowPress(bool value);

	UFUNCTION(BlueprintCallable)
	void NewNote();

	void HideNewNote();

	UFUNCTION(BlueprintCallable)
	void EnableCursor(bool value);
	
};
