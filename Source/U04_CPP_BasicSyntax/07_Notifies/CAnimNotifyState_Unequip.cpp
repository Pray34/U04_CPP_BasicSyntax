#include "CAnimNotifyState_Unequip.h"
#include "Global.h"
#include "../03_Character/IRifle.h"
#include "../06_Weapons/CRifle.h"

FString UCAnimNotifyState_Unequip::GetNotifyName_Implementation() const
{
	return "Unequip";
}

void UCAnimNotifyState_Unequip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	if (!MeshComp)return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (!rifleInterface) return;

	//Socket Attach
	rifleInterface->GetRifle()->Begin_UnEquip();
}

void UCAnimNotifyState_Unequip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (!MeshComp)return;

	IIRifle* rifleInterface = Cast<IIRifle>(MeshComp->GetOwner());
	if (!rifleInterface) return;

	//Socket Attach
	rifleInterface->GetRifle()->End_UnEquip();
}
