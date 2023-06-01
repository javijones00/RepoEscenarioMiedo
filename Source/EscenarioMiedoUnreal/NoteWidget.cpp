// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetTree.h"
#include "HUDManager.h"
#include "BaseTerrorConfiguration.h"



void UNoteWidget::ConfigureNote(FText NoteText,ABaseTerrorConfiguration* TargetTerror, AGetableNote* NextNote, UAudioComponent* NoteSound)
{
    if(NoteTextBlock)
    {
        NoteTextBlock->SetText(NoteText);
    }
    CurrentTerror = TargetTerror;
    FollowingNote= NextNote;
    NoteFX=NoteSound;
    
}
void UNoteWidget::SetUIManager(AHUDManager* CurrentUIManager)
{
    UIManager = CurrentUIManager;
}

AHUDManager* UNoteWidget::GetUIManager()
{
  return UIManager;
}

 
ABaseTerrorConfiguration*  UNoteWidget::GetCurrentTerror()
{
    return CurrentTerror;
}

AGetableNote* UNoteWidget::GetNextNote()
{
    return FollowingNote;
}

UAudioComponent* UNoteWidget::GetNoteSound()
{
    return NoteFX;
}



