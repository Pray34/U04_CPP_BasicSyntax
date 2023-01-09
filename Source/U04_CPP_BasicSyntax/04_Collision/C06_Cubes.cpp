#include "C06_Cubes.h"
#include "Global.h"
#include "C05_MultiTrigger.h"
#include "Components/StaticMeshComponent.h"

AC06_Cubes::AC06_Cubes()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> cubeAsset(TEXT("StaticMesh'/Game/Meshes/SM_Cube.SM_Cube'"));

	for (int32 i = 0; i < 3; i++)
	{
		FString name;
		name.Append("Cube");
		name.Append(FString::FromInt(i));
		Cubes[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(*name));
		Cubes[i]->SetupAttachment(Scene);

		if (cubeAsset.Succeeded())
			Cubes[i]->SetStaticMesh(cubeAsset.Object);

		Cubes[i]->SetRelativeLocation(FVector(0, i * 200, 0));
	}
}

void AC06_Cubes::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC05_MultiTrigger::StaticClass(), actors);
	if (actors.Num() < 1) return; //nullcheck

	AC05_MultiTrigger* multiTrigger = Cast<AC05_MultiTrigger>(actors[0]);
	if (!multiTrigger) return; //nullcheck

	multiTrigger->OnMultiBeginOverlap.AddUFunction(this, "OnStartFalling");

	for (int32 i = 0; i < 3; i++)
	{
		FTransform transform = Cubes[i]->GetComponentToWorld(); //Component의 위치를 가져오는 부분 (액터자체가 아님)
		FirstLocations[i] = transform.GetLocation();
	}
}

void AC06_Cubes::OnStartFalling(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
	{
		Cubes[i]->SetSimulatePhysics(false); 
		Cubes[i]->SetWorldLocation(FirstLocations[i]);
	}

	Cubes[InIndex]->SetSimulatePhysics(true); //물리엔진(중력) 적용
}
