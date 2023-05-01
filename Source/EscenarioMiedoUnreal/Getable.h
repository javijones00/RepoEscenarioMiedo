// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Getable.generated.h"

UCLASS()
class ESCENARIOMIEDOUNREAL_API AGetable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGetable();

	virtual void GetableGot();

	virtual void ShowPress(bool press);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category="Componentes", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComponent;
	UPROPERTY(EditDefaultsOnly, Category="Componentes", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* GetableMesh;

	UPROPERTY(EditAnywhere, Category="UIManager", meta = (AllowPrivateAccess = "true"))
	class AUIManager* UIManager;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;




};
