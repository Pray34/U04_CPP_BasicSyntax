#include "CAnimInstance.h"
#include "Global.h"
#include "CPlayer.h"

void UCAnimInstance::NativeBeginPlay()
{
	Player = Cast<ACPlayer>(TryGetPawnOwner()); //Cast
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (!Player) return;
	//현재 NativeUpdateAnimation 함수는 매 프레임마다 돌기 때문에 NullCheck를 반드시 해줘야한다

	Speed = Player->GetVelocity().Size2D(); //Size : 언리얼에서 Length 와 비슷한 의미
}