#include "C03_LightTrigger.h"
#include "Global.h"

void AC03_LightTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC03_LightTrigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC03_LightTrigger::ActorEndOverlap);

	//TODO. 딜리게이트 바인딩을 아직 안함
}

void AC03_LightTrigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if(OnBoxBeginOverlap.IsBound()) //null check
		OnBoxBeginOverlap.Execute();

	if (OnBoxBeginRandomLightColor.IsBound())
	{
		FString str;
		str = OnBoxBeginRandomLightColor.Execute(FLinearColor::MakeRandomColor());
		str = ("Random Color is ") + str;
		CLog::Log(str);
	}
}

void AC03_LightTrigger::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxEndOverlap.IsBound()) //null check
		OnBoxEndOverlap.Execute();
}