#include "C06_Cubes.h"
#include "Global.h"
#include "C05_MultiTrigger.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"

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

	UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), nullptr, TEXT("MaterialInstanceConstant'/Game/Materials/MAT_Surface_Inst.MAT_Surface_Inst'"));
	UMaterialInstanceConstant* material = Cast<UMaterialInstanceConstant>(obj);
	if (!material) return;

	for (int32 i = 0; i < 3; i++)
	{
		FTransform transform = Cubes[i]->GetComponentToWorld(); //Component�� ��ġ�� �������� �κ� (������ü�� �ƴ�)
		FirstLocations[i] = transform.GetLocation();


		UMaterialInstanceDynamic* dynamicMaterial = UMaterialInstanceDynamic::Create(material, nullptr); //InstanceDynamic�� �����ڿ��� ���� �� ����
		Cubes[i]->SetMaterial(0, dynamicMaterial);
	}

}

void AC06_Cubes::OnStartFalling(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
	{
		Cubes[i]->SetWorldLocation(FirstLocations[i]);
		Cubes[i]->SetSimulatePhysics(false); 

		UMaterialInstanceDynamic* dynamicMaterial = Cast<UMaterialInstanceDynamic>(Cubes[i]->GetMaterial(0));
		if (!dynamicMaterial) return;
		dynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor(0.5f, 0.5f, 0.5f));
	}

	Cubes[InIndex]->SetSimulatePhysics(true); //��������(�߷�) ����

	//���׸��� �� ����
	UMaterialInstanceDynamic* dynamicMaterial = Cast<UMaterialInstanceDynamic>(Cubes[InIndex]->GetMaterial(0));
	if (!dynamicMaterial) return;
	dynamicMaterial->SetVectorParameterValue("BaseColor", InColor);
}
