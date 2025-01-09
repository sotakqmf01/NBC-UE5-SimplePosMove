// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor() : start(0.0f, 0.0f), evCnt(0), totalDist(0)
{
 	// Tick 기능을 사용하기 위해서는 해당 값을 true로 설정해야 한다
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("Player set :  (%d, %d)"), start.X, start.Y);		// 컴파일 안됨
	UE_LOG(LogTemp, Warning, TEXT("Player set :  (%.2f, %.2f)"), start.X, start.Y);
	

	for (int i = 0; i < 10; i++) {
		// 이동하기 전 위치 저장
		FVector2D prev;
		prev.X = start.X;
		prev.Y = start.Y;
		
		// 이동
		move();

		// 이동거리 출력
		float dist = distance(prev, start);
		UE_LOG(LogTemp, Warning, TEXT("move distance : %f"), dist);

		totalDist += dist;

		// 이벤트 발생 확률 50%
		int prob = FMath::RandRange(1, 100);
		if (prob >= 51)
			createEvent();
	}

	// 총 이동거리 및 이벤트 발생 횟수 출력
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %f"), totalDist);
	UE_LOG(LogTemp, Warning, TEXT("(0, 0) to (%.2f, %.2f) distance : %f"),
		start.X, start.Y, distance(FVector2D(0.0f, 0.0f), start));
	UE_LOG(LogTemp, Warning, TEXT("Event Count : %d"), evCnt);

}

// Called every frame
void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Tick called with DeltaTime : %f"), DeltaTime);
}

// 거리 계산
float AMoveActor::distance(FVector2D prev, FVector2D curr)
{
	//FVector2D(curr - prev).Size();

	float dx = curr.X - prev.X;
	float dy = curr.Y - prev.Y;

	return FMath::Sqrt(dx * dx + dy * dy);
}

// 랜덤하게 이동 + 이동한 좌표 출력
void AMoveActor::move()
{
	start.X = start.X + step();
	start.Y = start.Y + step();

	UE_LOG(LogTemp, Warning, TEXT("Player move : (%.2f, %.2f)"), start.X, start.Y);
}

// 랜덤한 이동에 사용될 랜덤한 수치
int AMoveActor::step()
{
	//return 5.0f;
	return FMath::RandRange(0, 1);
}

// 이벤트 발생 여부 출력
int AMoveActor::createEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("---------EVENT---------"));
	evCnt++;
	return 0;
}

int AMoveActor::UE5()
{

	return 0;
}
