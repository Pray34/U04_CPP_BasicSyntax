#include "C02_StaticMesh.h"
#include "Components/StaticMeshComponent.h"

AC02_StaticMesh::AC02_StaticMesh()
{
	//PrimaryActorTick.bCanEverTick = true; //Tick�� ����Ϸ��� �ݵ�� �ʿ�
	CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void AC02_StaticMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

