// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PreviousLocation= FVector2D(0. 0);
	CurrnetLocation= FVector2D(0. 0); // 시작점 0.0 초기화 하는것
	TotalDistance = 0.f;
	TotalEventCount = 0;
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Initial Location : (% f, % f)"), CurrentLocation.X, CurrentLocation.Y);
	Move(10, 50);
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMyActor2::Step()
{
	return FMath::RandRange(0, 1);
}

 
void AMyActor2::Move(int32 MoveCount, float Probability)

	for (int32 i = 0; i < MoveCount; ++i)
	{
		PreviousLocation = CurrentLocation;
		CurrentLocation.X += Step();
		CurrentLocation.Y += Step();
		TriggerEventWithProbability(Probability);

		float MoveDistance = Distance(CurrentLocation, PreviousLocation);
		TotaDistance += MoveDistance;
			UE_LOG(LogTemp, Warning, TEXT("STEP %d Location : (% f, % f), Moved Distance: %f"), i + 1, CurrentLocation.X, CurrentLocation.Y);
	}
	 
}

void AMyActor2::TriggerEventWithProbability(float Probability) 
{
	int32 RandomValue = FMath::RandRange(1, 100);
	if (RandomValue <= Probability)
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Occired"));
		++TotalEventCount;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Event Not Occired"));

}

float AMyActor2::Distance(FVector2D second, FVector2D first)
{
		float dx = second.X - first.X;
	float dy = second.Y - first.Y;
	return FMath::Sqrt(FMath::Square(dx) + FMath::Square(dy));
}