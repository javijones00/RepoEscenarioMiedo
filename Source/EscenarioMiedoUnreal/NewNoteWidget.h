// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NewNoteWidget.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API UNewNoteWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	class UTextBlock* NameTextBlock;

    int NOTE_COUNT;

public:

	void NewNoteCreated();

};
