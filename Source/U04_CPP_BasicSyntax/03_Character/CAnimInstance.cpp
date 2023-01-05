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
	//���� NativeUpdateAnimation �Լ��� �� �����Ӹ��� ���� ������ NullCheck�� �ݵ�� ������Ѵ�

	Speed = Player->GetVelocity().Size2D(); //Size : �𸮾󿡼� Length �� ����� �ǹ�
}