#include "C14_ExplosionTrigger.h"
#include "C13_Explosion.h"
#include "Global.h"

void AC14_ExplosionTrigger::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC13_Explosion::StaticClass(), actors);
	if (actors.Num() < 1) return;

	AC13_Explosion* explosion = Cast<AC13_Explosion>(actors[0]);
	if (!explosion) return;

	OnActorBeginOverlap.AddDynamic(explosion, &AC13_Explosion::OnExplosion);
}