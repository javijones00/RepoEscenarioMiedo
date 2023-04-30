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
	
};
