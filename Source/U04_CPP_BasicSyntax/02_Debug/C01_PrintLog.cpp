#include "C01_PrintLog.h"
#include "Global.h"

AC01_PrintLog::AC01_PrintLog()
{
	PrimaryActorTick.bCanEverTick = true;
	bVisible = false;
}

void AC01_PrintLog::BeginPlay()
{
	Super::BeginPlay();
	
	if (bVisible)
	{
		CLog::Print(1);
		CLog::Print(2, -2);
		CLog::Print(3, -3, 20.0f, FColor::Emerald);
		CLog::Print(4, -4, 20.0f, FColor::Purple);
		CLog::Print("Hell World",-5);
		CLog::Print(GetActorLocation(),-6);
		CLog::Print(GetActorRotation(),-7);
		
		CLog::Log(10);
		CLog::Log(PI);
		CLog::Log("Hello World");
		CLog::Log(GetActorLocation());
		CLog::Log(GetActorRotation());
		CLog::Log(__FILE__);
		PrintLine();
	}
}

void AC01_PrintLog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	CLog::Print(RunningTime, -8, 1.0f);
}

