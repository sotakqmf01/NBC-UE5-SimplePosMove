// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor() : start(0.0f, 0.0f), evCnt(0), totalDist(0)
{
 	// Tick ����� ����ϱ� ���ؼ��� �ش� ���� true�� �����ؾ� �Ѵ�
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("Player set :  (%d, %d)"), start.X, start.Y);		// ������ �ȵ�
	UE_LOG(LogTemp, Warning, TEXT("Player set :  (%.2f, %.2f)"), start.X, start.Y);
	

	for (int i = 0; i < 10; i++) {
		// �̵��ϱ� �� ��ġ ����
		FVector2D prev;
		prev.X = start.X;
		prev.Y = start.Y;
		
		// �̵�
		move();

		// �̵��Ÿ� ���
		float dist = distance(prev, start);
		UE_LOG(LogTemp, Warning, TEXT("move distance : %f"), dist);

		totalDist += dist;

		// �̺�Ʈ �߻� Ȯ�� 50%
		int prob = FMath::RandRange(1, 100);
		if (prob >= 51)
			createEvent();
	}

	// �� �̵��Ÿ� �� �̺�Ʈ �߻� Ƚ�� ���
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

// �Ÿ� ���
float AMoveActor::distance(FVector2D prev, FVector2D curr)
{
	//FVector2D(curr - prev).Size();

	float dx = curr.X - prev.X;
	float dy = curr.Y - prev.Y;

	return FMath::Sqrt(dx * dx + dy * dy);
}

// �����ϰ� �̵� + �̵��� ��ǥ ���
void AMoveActor::move()
{
	start.X = start.X + step();
	start.Y = start.Y + step();

	UE_LOG(LogTemp, Warning, TEXT("Player move : (%.2f, %.2f)"), start.X, start.Y);
}

// ������ �̵��� ���� ������ ��ġ
int AMoveActor::step()
{
	//return 5.0f;
	return FMath::RandRange(0, 1);
}

// �̺�Ʈ �߻� ���� ���
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
