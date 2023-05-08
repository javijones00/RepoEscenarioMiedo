// Fill out your copyright notice in the Description page of Project Settings.


#include "GetableNote.h"
#include "UIManager.h"
#include "BaseTerrorConfiguration.h"

void AGetableNote::GetableGot()
{
    if(UIManager)
    {
        UIManager->CreateNoteUI(NoteText, SpecificTerrorConfig);
    }
    // if(SpecificTerrorConfig)
    // {
    //     SpecificTerrorConfig->PerformChanges();
    // }
	
    Super::GetableGot();
}