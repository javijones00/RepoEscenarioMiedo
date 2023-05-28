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



void UNoteWidget::ConfigureNote(FText NoteText,ABaseTerrorConfiguration* TargetTerror)
{
    if(NoteTextBlock)
    {
        NoteTextBlock->SetText(NoteText);
    }
    CurrentTerror = TargetTerror;
    
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