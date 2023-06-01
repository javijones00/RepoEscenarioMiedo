// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Getable.h"
#include "GetableNote.generated.h"

/**
 * 
 */
UCLASS()
class ESCENARIOMIEDOUNREAL_API AGetableNote : public AGetable
{
	GENERATED_BODY()


public:

	virtual void GetableGot() override;

protected:

	UPROPERTY(EditAnywhere, Category="Note Specification", meta = (AllowPrivateAccess = "true"))
	FText NoteText;
	UPROPERTY(EditAnywhere, Category="Note Specification", meta = (AllowPrivateAccess = "true"))
	class ABaseTerrorConfiguration* SpecificTerrorConfig;
	UPROPERTY(EditAnywhere, Category="Note Specification", meta = (AllowPrivateAccess = "true"))
	class AGetableNote* NextNote;
	UPROPERTY(EditAnywhere,Category="Note Specification", meta = (AllowPrivateAccess = "true"))
	class UAudioComponent* NoteSound;

	
};
