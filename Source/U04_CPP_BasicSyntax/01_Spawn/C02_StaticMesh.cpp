#include "C02_StaticMesh.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

AC02_StaticMesh::AC02_StaticMesh()
{
	//PrimaryActorTick.bCanEverTick = true; //Tick�� ����Ϸ��� �ݵ�� �ʿ�
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("/Game/Meshes/SM_Cube"));
	//ConstructorHelpers : ������ �ȿ����� ��밡��
	//FObjectFinder : ������ �ҷ����� �Լ�

	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}

void AC02_StaticMesh::BeginPlay()
{
	Super::BeginPlay();

	UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), nullptr, TEXT("MaterialInstanceConstant'/Game/Materials/MAT_Surface_Inst.MAT_Surface_Inst'"));
	//StaticLoadObject : �����ڰ� �ƴ� ������ FObjectFinder�� ����� �Լ��� ����ϴ� ���

	UMaterialInstanceConstant* material;
	material = Cast<UMaterialInstanceConstant>(obj);
	//obj : �ڵ尡 �� ��������
	//Cast<> : �𸮾� ���� dynamic_cast * �����͸� ������ �ʴ´�

	if (material == nullptr) return; //nullptr �ݵ�� üũ

	DynamicMaterial = UMaterialInstanceDynamic::Create(material, nullptr);

	Mesh->SetMaterial(0, DynamicMaterial);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeParameter", 0.5f, true); //Set timer by Function
}

void AC02_StaticMesh::ChangeParameter()
{
	FLinearColor color;

	color.R = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
	color.G = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
	color.B = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
	color.A = 1.0f;

	DynamicMaterial->SetVectorParameterValue("BaseColor", color);
	DynamicMaterial->SetScalarParameterValue("Metallic", color.R);
	DynamicMaterial->SetScalarParameterValue("Roughness", color.G);
}
