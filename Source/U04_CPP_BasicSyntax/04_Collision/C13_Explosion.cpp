#include "C13_Explosion.h"
#include "Particles/ParticleSystemComponent.h"
#include "Global.h"
#include "../03_Character/CPlayer.h"

AC13_Explosion::AC13_Explosion()
{
	Particle = CreateDefaultSubobject<UParticleSystemComponent>("Particle");
	Particle->SetupAttachment(Scene);

	ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset(TEXT("ParticleSystem'/Game/Particles/P_Impact_FireBall.P_Impact_FireBall'"));
	if (particleAsset.Succeeded())
		Particle->SetTemplate(particleAsset.Object);

}

void AC13_Explosion::OnExplosion(class AActor* OverlappedActor, class AActor* OtherActor)
{
	ACPlayer* player = Cast<ACPlayer>(OtherActor);
	if (!player) return;

	//SphereTrace
	FVector start = GetActorLocation();
	FVector end = FVector(start.X, start.Y, start.Z + 100.0f);

	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(EObjectTypeQuery::ObjectTypeQuery4);

	TArray<AActor*> ignoresActors;
	TArray<FHitResult> hitResults;

	bool IsBoom = UKismetSystemLibrary::SphereTraceMultiForObjects
		(GetWorld(), start, end, 1000, objectTypes, false, ignoresActors, EDrawDebugTrace::ForDuration, hitResults, true);
	
	if (IsBoom)
	{
		//���
		Particle->ResetParticles();
		Particle->SetActive(true);

		for (const FHitResult& hitResult : hitResults)
		{
			UStaticMeshComponent* meshCompo = Cast<UStaticMeshComponent>(hitResult.GetActor()->GetRootComponent());
			if (!!meshCompo)
				meshCompo->AddRadialImpulse(start, 1000, 15e5 / meshCompo->GetMass(), ERadialImpulseFalloff::RIF_Linear);
		}
	}
}