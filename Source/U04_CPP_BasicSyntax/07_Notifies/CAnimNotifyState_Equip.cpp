#include "CAnimNotifyState_Equip.h"
#include "Global.h"
#include "../03_Character/IRifle.h"
#include "../06_Weapons/CRifle.h"

FString UCAnimNotifyState_Equip::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCAnimNotifyState_Equip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	if (!MeshComp)return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (!rifleInterface) return;
	
	//Socket Attach
	rifleInterface->GetRifle()->Begin_Equip();
}

void UCAnimNotifyState_Equip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (!MeshComp)return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (!rifleInterface) return;

	//Socket Attach
	rifleInterface->GetRifle()->End_Equip();
}
