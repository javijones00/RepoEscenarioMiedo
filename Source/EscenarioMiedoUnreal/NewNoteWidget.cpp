// Fill out your copyright notice in the Description page of Project Settings.


#include "NewNoteWidget.h"
#include "Components/TextBlock.h"

void UNewNoteWidget::NewNoteCreated()
{
    NOTE_COUNT +=1;
    FString text = "Has recogido ";
    text.AppendInt(NOTE_COUNT);
    text.Append(" nota(s) de 6");
    FText uiText= FText::FromString(text);
    NameTextBlock->SetText(uiText);
}