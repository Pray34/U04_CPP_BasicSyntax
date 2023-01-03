#include "C02_DrawDebug.h"
#include "Global.h"

AC02_DrawDebug::AC02_DrawDebug()
{
	PrimaryActorTick.bCanEverTick = true;

	RelativeLocation[0] = FVector(500, 0, 0);
	RelativeLocation[1] = FVector(0, 500, 0);
	RelativeLocation[2] = FVector(-500, 0, 0);
	RelativeLocation[3] = FVector(-1000, 0, 0);

	box = FBox(FVector(-50, -100, -50), FVector(50, 100, 50));
}

void AC02_DrawDebug::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox
	(
		GetWorld(),
		GetActorLocation() + box.GetCenter(),
		box.GetExtent(),
		FColor::Red,
		true
	);
}

void AC02_DrawDebug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int32 i = 0; i < 4; i++)
	{
		WorldLocation[i] = GetActorLocation() + RelativeLocation[i];
	}

	DrawDebugSolidBox(GetWorld(), WorldLocation[0], box.GetExtent(), FColor::Emerald);
	DrawDebugPoint(GetWorld(), WorldLocation[1], 10.0f, FColor::Cyan); //Point는 2D 공간에서 그려진다
	DrawDebugSphere(GetWorld(), WorldLocation[2], 100.0f, 20, FColor::Green);
	DrawDebugCircle(GetWorld(), WorldLocation[3], 100.0f, 20, FColor::Purple);
	DrawDebugDirectionalArrow(GetWorld(), WorldLocation[1], WorldLocation[3], 100.0f, FColor::Red, false, -1.0f, 0U, 10.0f);
}

