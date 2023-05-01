// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "NoteWidget.h"
#include "Blueprint/UserWidget.h"

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
    CurrentNoteWidget = CreateWidget<UNoteWidget>(GetWorld(),MyNoteWidget,TEXT("NoteUI"));
	CurrentNoteWidget->AddToViewport();
	CurrentNoteWidget->SetVisibility(ESlateVisibility::Hidden);

    CurrentPressWidget = CreateWidget<UUserWidget>(GetWorld(),PressWidget,TEXT("Press"));
	CurrentPressWidget->AddToViewport();
	CurrentPressWidget->SetVisibility(ESlateVisibility::Hidden);

}

void  AUIManager::CreateNoteUI(FText noteText)
{
    if(CurrentNoteWidget)
    {
        CurrentNoteWidget->SetNoteText(noteText);
        CurrentNoteWidget->SetVisibility(ESlateVisibility::Visible);
    }
    
}

void  AUIManager::ShowPress(bool press)
{
    if(CurrentPressWidget)
    {
        if(press)
        {
            CurrentPressWidget->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            CurrentPressWidget->SetVisibility(ESlateVisibility::Hidden);
        }
       
    }
    
}
