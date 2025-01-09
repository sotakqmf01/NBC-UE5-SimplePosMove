// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class HELLO_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float distance(FVector2D prev, FVector2D curr);

	void move();

	int step();

	int createEvent();

	int UE5();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NBC");
	FVector2D start;
	int evCnt;
	float totalDist;
};
