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
    MonsterActivated();
}




void AMonsterTerrorConfiguration::StartChasingInvoked()
{
    UBlackboardComponent* BlackBoardRef = UAIBlueprintHelperLibrary::GetBlackboard(MonsterReference);
    
    if(BlackBoardRef)
    {
        BlackBoardRef->SetValueAsBool(FName("IsChasingMode"),true);
        MonsterChasing();
    }
   
    
    
}
void AMonsterTerrorConfiguration::Config(bool Activated)
{
    UBlackboardComponent* BlackBoardRef = UAIBlueprintHelperLibrary::GetBlackboard(MonsterReference);
    if(Activated)
    {
        MonsterReference->SetActorHiddenInGame(false);
        GetWorld()->GetTimerManager().SetTimer(ChasingHandle,this,&AMonsterTerrorConfiguration::StartChasingInvoked,TimeUntilChasing,false);
        MonsterActivated();
    }
    else
    {
        MonsterReference->SetActorHiddenInGame(true);
        GetWorld()->GetTimerManager().ClearTimer(ChasingHandle);
        BlackBoardRef->SetValueAsBool(FName("IsChasingMode"),false);
        BlackBoardRef->SetValueAsBool(FName("IsStanding"),false);
        BlackBoardRef->SetValueAsBool(FName("CharacterInRange"),false);
        MonsterDestroyed();

    }
}