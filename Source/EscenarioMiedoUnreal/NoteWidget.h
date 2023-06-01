// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NoteWidget.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API UNoteWidget : public UUserWidget
{
	GENERATED_BODY()


	
protected:


	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	class UTextBlock* NoteTextBlock;
	UPROPERTY(BlueprintReadOnly, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	class AHUDManager* UIManager;

	class UPanelWidget* RootPanel;
	//UPROPERTY(BlueprintReadOnly, Category="Terror Configuration", meta = (AllowPrivateAccess = "true"))
	class ABaseTerrorConfiguration* CurrentTerror;
	class AGetableNote* FollowingNote;
	class UAudioComponent* NoteFX;

public:

	void ConfigureNote(FText NoteText, class ABaseTerrorConfiguration* TargetTerror, class AGetableNote* NextNote, class UAudioComponent* NoteSound);
	
	void SetUIManager(class AHUDManager* CurrentUIManager);
	
	UFUNCTION(BlueprintCallable)
	class ABaseTerrorConfiguration* GetCurrentTerror();

	UFUNCTION(BlueprintCallable)
	class AHUDManager* GetUIManager();

	UFUNCTION(BlueprintCallable)
	class AGetableNote* GetNextNote();

	UFUNCTION(BlueprintCallable)
	class UAudioComponent* GetNoteSound();
};
