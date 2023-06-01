// Fill out your copyright notice in the Description page of Project Settings.


#include "GetableNote.h"
#include "HUDManager.h"
#include "BaseTerrorConfiguration.h"

void AGetableNote::GetableGot()
{
    if(UIManager)
    {
        NoteText = NoteText.Replace(TEXT("\\n"),TEXT("\n"));
        FText ConvertedText = FText::FromString(NoteText);
        UIManager->CreateNoteUI(ConvertedText, SpecificTerrorConfig,NextNote,NoteSound);
    }
    // if(SpecificTerrorConfig)
    // {
    //     SpecificTerrorConfig->PerformChanges();
    // }
	
    Super::GetableGot();
}