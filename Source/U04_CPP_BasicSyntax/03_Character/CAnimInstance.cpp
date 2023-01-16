#include "CAnimInstance.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "../03_Character/IRifle.h"
#include "../06_Weapons/CRifle.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner()); //Cast
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!OwnerCharacter) return;
	//���� NativeUpdateAnimation �Լ��� �� �����Ӹ��� ���� ������ NullCheck�� �ݵ�� ������Ѵ�

	Speed = OwnerCharacter->GetVelocity().Size2D(); //Size : �𸮾󿡼� Length �� ����� �ǹ�

	IIRifle* rifleInterface = Cast<IIRifle>(OwnerCharacter);
	if (!!rifleInterface)
	{
		bEquipped = rifleInterface->GetRifle()->IsEquipped();

	}
}