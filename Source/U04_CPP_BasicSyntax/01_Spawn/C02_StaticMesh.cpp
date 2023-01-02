#include "C02_StaticMesh.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

AC02_StaticMesh::AC02_StaticMesh()
{
	//PrimaryActorTick.bCanEverTick = true; //Tick을 사용하려면 반드시 필요
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("/Game/Meshes/SM_Cube"));
	//ConstructorHelpers : 생성자 안에서만 사용가능
	//FObjectFinder : 에셋을 불러오는 함수

	if (meshAsset.Succeeded())
		Mesh->SetStaticMesh(meshAsset.Object);
}

void AC02_StaticMesh::BeginPlay()
{
	Super::BeginPlay();

	UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), nullptr, TEXT("MaterialInstanceConstant'/Game/Materials/MAT_Surface_Inst.MAT_Surface_Inst'"));
	//StaticLoadObject : 생성자가 아닌 곳에서 FObjectFinder와 비슷한 함수를 사용하는 방법

	UMaterialInstanceConstant* material;
	material = Cast<UMaterialInstanceConstant>(obj);
	//obj : 코드가 길어서 변수생성
	//Cast<> : 언리얼 전용 dynamic_cast * 포인터를 붙이지 않는다

	if (material == nullptr) return; //nullptr 반드시 체크

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
