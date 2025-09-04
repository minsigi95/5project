// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class MYPROJECT_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	FVector2D CurrnetLocation; // 현재 위치를 담는 좌표
	FVector2D PreviousLocation; // 이전 위치를 담는 좌표

	float TotalDistance;
	int32 TotalEventCount;

	int32 Step();
	void Move(int32 MoveCount, float Probability);
	void TriggerEventWithProbability(float Probability);
	float Distance(FVector second, FVector first);


};












