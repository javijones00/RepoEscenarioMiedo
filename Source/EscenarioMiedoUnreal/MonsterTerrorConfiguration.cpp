// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterTerrorConfiguration.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include"Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"


void AMonsterTerrorConfiguration::PerformChanges()
{
    MonsterReference->SetActorHiddenInGame(false);
    GetWorld()->GetTimerManager().SetTimer(ChasingHandle,this,&AMonsterTerrorConfiguration::StartChasingInvoked,TimeUntilChasing,false);
}
void AMonsterTerrorConfiguration::StartChasingInvoked()
{
    UBlackboardComponent* BlackBoardRef =MonsterReference->FindComponentByClass<UBlackboardComponent>();
    if(BlackBoardRef)
    {
        BlackBoardRef->SetValueAsBool(FName("IsChasingMode"),true);
    }
    
    
}