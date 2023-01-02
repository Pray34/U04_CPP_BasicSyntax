#include "C02_Spawner.h"
#include "C02_StaticMesh.h"

AC02_Spawner::AC02_Spawner()
{

}

void AC02_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 4; i++)
	{
		FTransform transform; //지역변수는 소문자로 시작
		//FVector location = FVector(0, i * 200, 50);

		Meshes[i] = GetWorld()->SpawnActor<AC02_StaticMesh>(SpawnClasses[i], transform);

		FVector worldLocation =  GetActorLocation();

		Meshes[i]->SetActorLocation(FVector(worldLocation.X, worldLocation.Y + i * 200, worldLocation.Z + 50));
	}
}
