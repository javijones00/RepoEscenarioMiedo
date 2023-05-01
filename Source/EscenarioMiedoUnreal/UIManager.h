// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API AUIManager : public AActor
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditAnywhere, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UNoteWidget> MyNoteWidget;
	UPROPERTY(EditAnywhere, Category="Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> PressWidget;

	class UNoteWidget* CurrentNoteWidget;
	class UUserWidget* CurrentPressWidget;

	virtual void BeginPlay() override;


public:

	void CreateNoteUI(FText noteText);

	void ShowPress(bool value);
	
};
