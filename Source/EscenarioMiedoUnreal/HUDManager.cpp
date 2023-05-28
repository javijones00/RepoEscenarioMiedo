// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDManager.h"
#include "NoteWidget.h"
#include "Blueprint/UserWidget.h"
#include "BaseTerrorConfiguration.h"
#include "NewNoteWidget.h"
#include "SandboxOptions.h"
#include "AudioTerrorConfiguration.h"
#include "IluminationTerrorConfiguration.h"
#include "MonsterTerrorConfiguration.h"
#include "VisibilityTerrorConfiguration.h"
#include "PostProcessTerrorConfig.h"
#include "Blueprint/UserWidget.h"

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

    CurrentSandbox = CreateWidget<USandboxOptions>(GetWorld(),SandboxWidget,TEXT("SandboxOptions"));
    // CurrentSandbox->AddToViewport();
    // CurrentSandbox->SetVisibility(ESlateVisibility::Hidden); 
    CurrentSandbox->SetConfigurations(AudioConfig,IlumConfig,PPConfig,VisibilityConfig,MonsterConfig);

    

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
void AHUDManager::ShowSandBox(bool value)
{

	// CurrentSandbox->SetVisibility(value ? ESlateVisibility::Visible : ESlateVisibility::Hidden);  
    if(value)
    {
        CurrentSandbox->AddToViewport(2);
    }
    else
    {
        CurrentSandbox->RemoveFromParent();
    }
}
void AHUDManager::HideNewNote()
{
    CurrentNewNoteWidget->SetVisibility(ESlateVisibility::Hidden);
}