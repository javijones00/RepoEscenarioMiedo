// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDManager.h"
#include "NoteWidget.h"
#include "Blueprint/UserWidget.h"
#include "BaseTerrorConfiguration.h"
#include "NewNoteWidget.h"

void AHUDManager::BeginPlay()
{
	Super::BeginPlay();
    CurrentPC = GetWorld()->GetFirstPlayerController();

    CurrentNewNoteWidget = CreateWidget<UNewNoteWidget>(GetWorld(),NewNoteWidget,TEXT("NewNoteUI"));
	CurrentNewNoteWidget->AddToViewport();
	CurrentNewNoteWidget->SetVisibility(ESlateVisibility::Hidden);

    CurrentNoteWidget = CreateWidget<UNoteWidget>(GetWorld(),MyNoteWidget,TEXT("NoteUI"));
	CurrentNoteWidget->AddToViewport();
	CurrentNoteWidget->SetVisibility(ESlateVisibility::Hidden);
    CurrentNoteWidget->SetUIManager(this);

    CurrentPressWidget = CreateWidget<UUserWidget>(GetWorld(),PressWidget,TEXT("Press"));
	CurrentPressWidget->AddToViewport();
	CurrentPressWidget->SetVisibility(ESlateVisibility::Hidden);

}

void  AHUDManager::CreateNoteUI(FText noteText, ABaseTerrorConfiguration* CurrentTerror)
{
    if(CurrentNoteWidget)
    {
        CurrentNoteWidget->ConfigureNote(noteText,CurrentTerror);
        CurrentNoteWidget->SetVisibility(ESlateVisibility::Visible);
        EnableCursor(true);
    }
    
}

void  AHUDManager::ShowPress(bool press)
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

void  AHUDManager::EnableCursor(bool value)
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

void AHUDManager::NewNote()
{
     CurrentNewNoteWidget->SetVisibility(ESlateVisibility::Visible);
     CurrentNewNoteWidget->NewNoteCreated();
     GetWorld()->GetTimerManager().SetTimer(NewNoteHandle,this,&AHUDManager::HideNewNote,6,false);
}
void AHUDManager::HideNewNote()
{
    CurrentNewNoteWidget->SetVisibility(ESlateVisibility::Hidden);
}