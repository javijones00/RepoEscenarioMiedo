// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "NoteWidget.h"
#include "Blueprint/UserWidget.h"
#include "BaseTerrorConfiguration.h"

void AUIManager::BeginPlay()
{
	Super::BeginPlay();
    CurrentPC = GetWorld()->GetFirstPlayerController();
    CurrentNoteWidget = CreateWidget<UNoteWidget>(GetWorld(),MyNoteWidget,TEXT("NoteUI"));
	CurrentNoteWidget->AddToViewport();
	CurrentNoteWidget->SetVisibility(ESlateVisibility::Hidden);
    CurrentNoteWidget->SetUIManager(this);

    CurrentPressWidget = CreateWidget<UUserWidget>(GetWorld(),PressWidget,TEXT("Press"));
	CurrentPressWidget->AddToViewport();
	CurrentPressWidget->SetVisibility(ESlateVisibility::Hidden);

}

void  AUIManager::CreateNoteUI(FText noteText, ABaseTerrorConfiguration* CurrentTerror)
{
    if(CurrentNoteWidget)
    {
        CurrentNoteWidget->ConfigureNote(noteText,CurrentTerror);
        CurrentNoteWidget->SetVisibility(ESlateVisibility::Visible);
        EnableCursor(true);
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

void  AUIManager::EnableCursor(bool value)
{
    if(CurrentPC)
    {
        CurrentPC->bShowMouseCursor = value;
        CurrentPC->bEnableClickEvents = value; 
        CurrentPC->bEnableMouseOverEvents = value;
        if(value)
        {
            CurrentPC->GetPawn()->DisableInput(CurrentPC);
        }
        else
        {
            CurrentPC->GetPawn()->EnableInput(CurrentPC);
        }
    
    }
   
}
