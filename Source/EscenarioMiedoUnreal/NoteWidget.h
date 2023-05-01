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


	class UPanelWidget* RootPanel;

public:

	void SetNoteText(FText NoteText);
};
