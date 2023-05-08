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
	class AUIManager* UIManager;

	class UPanelWidget* RootPanel;
	//UPROPERTY(BlueprintReadOnly, Category="Terror Configuration", meta = (AllowPrivateAccess = "true"))
	class ABaseTerrorConfiguration* CurrentTerror;

public:

	void ConfigureNote(FText NoteText, class ABaseTerrorConfiguration* TargetTerror);
	
	void SetUIManager(class AUIManager* CurrentUIManager);
	
	UFUNCTION(BlueprintCallable)
	class ABaseTerrorConfiguration* GetCurrentTerror();

	UFUNCTION(BlueprintCallable)
	class AUIManager* GetUIManager();
};
