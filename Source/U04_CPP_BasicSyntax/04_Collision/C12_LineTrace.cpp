#include "C12_LineTrace.h"
#include "Global.h"
#include "C11_LineTracePoint.h"
#include "../03_Character/CPlayer.h"
#include "Components/CapsuleComponent.h"

AC12_LineTrace::AC12_LineTrace()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AC12_LineTrace::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC11_LineTracePoint::StaticClass(), actors);
	if (actors.Num() < 1) return;

	Cylinders[0] = Cast<AC11_LineTracePoint>(actors[0]);
	Cylinders[1] = Cast<AC11_LineTracePoint>(actors[1]);

	OnLineTraceEvent.AddDynamic(this, &AC12_LineTrace::Ragdoll);
}

void AC12_LineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//[ Create Line Collision ]
	FVector start = Cylinders[0]->GetActorLocation();
	FVector end = Cylinders[1]->GetActorLocation();
	
	TArray<AActor*> ignoreActors;
	ignoreActors.Add(Cylinders[0]);
	ignoreActors.Add(Cylinders[1]);
	
	FHitResult hitResult;

	bool bCollision = UKismetSystemLibrary::LineTraceSingleByProfile(GetWorld(), start, end, "Pawn", false, ignoreActors, EDrawDebugTrace::ForOneFrame, hitResult, true, FLinearColor::Green, FLinearColor::Red);
	if (bCollision)
	{
		FLinearColor randomColor = FLinearColor::MakeRandomColor();
		OnLineTraceEvent.Broadcast(hitResult.GetActor(), randomColor);
	}
}

void AC12_LineTrace::Ragdoll(AActor* InActor, FLinearColor InColor)
{
	ACPlayer* player = Cast<ACPlayer>(InActor);
	if (!player) return;

	player->GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	player->GetMesh()->SetSimulatePhysics(true);

	player->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	FVector force = player->GetVelocity().GetSafeNormal() * 1e+5f;
	player->GetMesh()->AddImpulse(force);
	player->GetMesh()->GlobalAnimRateScale = 0.0f;
}
