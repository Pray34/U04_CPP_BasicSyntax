#include "C05_MultiTrigger.h"
#include "Global.h"

void AC05_MultiTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC05_MultiTrigger::ActorBeginOverlap);
}

void AC05_MultiTrigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnMultiBeginOverlap.IsBound()) //Multicast�� �ϳ��� ���ε��� �Ǿ������� true
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);
		FLinearColor color = FLinearColor::MakeRandomColor();

		OnMultiBeginOverlap.Broadcast(index, color); //Excute();
	}
}
