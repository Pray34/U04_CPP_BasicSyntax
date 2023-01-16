#include "CRifle.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

ACRifle::ACRifle()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/Weapons/Meshes/AR4/SK_AR4.SK_AR4'"));
	if(meshAsset.Succeeded())
		Mesh->SetSkeletalMesh(meshAsset.Object);

	//GetMontageAsset
	ConstructorHelpers::FObjectFinder<UAnimMontage> grabMontageAsset(TEXT("AnimMontage'/Game/Character/Montages/Rifle_Grab_Montage.Rifle_Grab_Montage'"));
	if (grabMontageAsset.Succeeded())
		GrabMontage = grabMontageAsset.Object;

	ConstructorHelpers::FObjectFinder<UAnimMontage> ungrabMontageAsset(TEXT("AnimMontage'/Game/Character/Montages/Rifle_UnGrab_Montage.Rifle_UnGrab_Montage'"));
	if (ungrabMontageAsset.Succeeded())
		UnGrabMontage = ungrabMontageAsset.Object;
}

ACRifle* ACRifle::Spawn(UWorld* InWorld, ACharacter* InOwnerCharacter) //static Function
{
	FActorSpawnParameters spawnParam; //구조체
	spawnParam.Owner = InOwnerCharacter; //Owner 세팅
	
	return InWorld->SpawnActor<ACRifle>(spawnParam); //SpawnActor 함수 결과값을 리턴
}

void ACRifle::Equip()
{
	if (bEquipped)return;
	if (bEquipping)return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(GrabMontage);
}

void ACRifle::UnEquip()
{
}

void ACRifle::BeginPlay()
{
	Super::BeginPlay();
	
	//Attach to Owner
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative,true), HolsterSocket);
}

void ACRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

