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
	//현재 NativeUpdateAnimation 함수는 매 프레임마다 돌기 때문에 NullCheck를 반드시 해줘야한다

	Speed = OwnerCharacter->GetVelocity().Size2D(); //Size : 언리얼에서 Length 와 비슷한 의미

	IIRifle* rifleInterface = Cast<IIRifle>(OwnerCharacter);
	if (!!rifleInterface)
	{
		bEquipped = rifleInterface->GetRifle()->IsEquipped();

	}
}