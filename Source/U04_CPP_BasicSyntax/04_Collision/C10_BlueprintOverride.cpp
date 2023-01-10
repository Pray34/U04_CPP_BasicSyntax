#include "C10_BlueprintOverride.h"
#include "Global.h"

void AC10_BlueprintOverride::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC10_BlueprintOverride::ActorBeginOverlap);
	OnActorBeginOverlap.AddDynamic(this, &AC10_BlueprintOverride::ActorEndOverlap);
}

void AC10_BlueprintOverride::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	SetBodyColor();
}

void AC10_BlueprintOverride::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{

}