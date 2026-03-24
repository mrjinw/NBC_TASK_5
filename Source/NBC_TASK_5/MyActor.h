#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class NBC_TASK_5_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

protected:
    int32 StepCount;
    int32 MaxSteps;

public:
    // [과제 2] 이동 함수 (Distance를 인자로 받음)
    void MoveActor(float Distance);

    // [과제 2] 회전 함수 (Angle을 인자로 받음)
    void TurnActor(float Angle);

    // [과제 2] 10회 랜덤 실행 로직
    void RunRandomProcess();

public:
    virtual void Tick(float DeltaTime) override;
};