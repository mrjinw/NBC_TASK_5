#include "MyActor.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false; // Tick 안 씀
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // [1] 시작 위치
    SetActorLocation(FVector(0.0f, 50.0f, 100.0f)); // Z 올려서 안 박히게

    StepCount = 0;
    MaxSteps = 10;

    UE_LOG(LogTemp, Warning, TEXT("BeginPlay Start"));

    // [2] 1초마다 실행
    GetWorld()->GetTimerManager().SetTimer(
        TimerHandle,
        this,
        &AMyActor::RunRandomProcess,
        1.0f,
        true
    );
}

// 이동
void AMyActor::MoveActor(float Distance)
{
    FVector Forward = GetActorForwardVector();
    FVector NewLocation = GetActorLocation() + Forward * Distance;

    SetActorLocation(NewLocation);

    // 콘솔 로그
    UE_LOG(LogTemp, Warning, TEXT("Move -> Location: %s"), *NewLocation.ToString());

    // 화면 로그
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green,
            FString::Printf(TEXT("Location: %s"), *NewLocation.ToString()));
    }
}

// 회전
void AMyActor::TurnActor(float Angle)
{
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += Angle;

    SetActorRotation(NewRotation);

    UE_LOG(LogTemp, Warning, TEXT("Turn -> Angle: %f"), Angle);
}

// 반복 실행
void AMyActor::RunRandomProcess()
{
    if (StepCount >= MaxSteps)
    {
        GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
        UE_LOG(LogTemp, Warning, TEXT("Process Finished"));
        return;
    }

    float RandDist = FMath::FRandRange(100.0f, 200.0f);
    float RandAngle = FMath::FRandRange(30.0f, 120.0f);

    UE_LOG(LogTemp, Warning, TEXT("---- Step %d ----"), StepCount + 1);

    MoveActor(RandDist);
    TurnActor(RandAngle);

    StepCount++;
}