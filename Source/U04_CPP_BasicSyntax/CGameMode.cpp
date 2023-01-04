#include "CGameMode.h"
#include "03_Character/CPlayer.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> pawnClass(TEXT("Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'"));
	//Ǯ��� : class Ref�� ���������� �ڿ���_C�� �ٿ����Ѵ�
	//��İ�� : _C�� ������ �ʾƵ��ȴ�

	if(pawnClass.Succeeded())
		DefaultPawnClass = pawnClass.Class;
}