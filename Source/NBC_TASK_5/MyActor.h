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

private:
    // 이동
    void MoveActor(float Distance);

    // 회전
    void TurnActor(float Angle);

    // 반복 실행
    void RunRandomProcess();

private:
    // 타이머
    FTimerHandle TimerHandle;

    int32 StepCount;
    int32 MaxSteps;
};