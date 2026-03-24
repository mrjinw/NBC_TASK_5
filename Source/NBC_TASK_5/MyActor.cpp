#include "MyActor.h"
#include "Engine/Engine.h" // [과제 3] 화면 로그 출력을 위해 필수

AMyActor::AMyActor()
{
    // 매 프레임 실행될 필요가 없으므로 false 설정
    PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    SetActorLocation(FVector(0.0f, 50.0f, 10.0f));

    StepCount = 0;
    MaxSteps = 10;
}

void AMyActor::MoveActor(float Distance)
{
    FVector Forward = GetActorForwardVector(); // 현재 바라보는 방향
    FVector NewLocation = GetActorLocation() + Forward * Distance;

    SetActorLocation(NewLocation);

    if (GEngine)
    {
        FString PosLog = FString::Printf(TEXT("Current Location: %s"), *NewLocation.ToString());
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, PosLog);
    }
}

void AMyActor::TurnActor(float Angle)
{
    // 현재 회전값에서 Yaw(Z축 회전) 방향으로 Angle만큼 회전
    FRotator NewRotation = GetActorRotation() + FRotator(0.0f, Angle, 0.0f);
    SetActorRotation(NewRotation);
}

void AMyActor::RunRandomProcess()
{
    for (int32 i = 0; i < 10; i++)
    {
        // 무작위 거리(0~200)와 무작위 각도(0~360) 생성
        float RandDist = FMath::FRandRange(0.0f, 200.0f);
        float RandAngle = FMath::FRandRange(0.0f, 360.0f);

        MoveActor(RandDist);
        TurnActor(RandAngle);
    }
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (StepCount < MaxSteps)
    {
        float RandDist = FMath::FRandRange(0.0f, 200.0f);
        float RandAngle = FMath::FRandRange(0.0f, 360.0f);

        MoveActor(RandDist);
        TurnActor(RandAngle);

        StepCount++;
    }
}