// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetTree.h"



void UNoteWidget::SetNoteText(FText NoteText)
{
    if(NoteTextBlock)
    {
        NoteTextBlock->SetText(NoteText);
    }
    
}