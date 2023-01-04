#include "CGameMode.h"
#include "03_Character/CPlayer.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> pawnClass(TEXT("Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'"));
	//풀경로 : class Ref를 가져오려면 뒤에다_C를 붙여야한다
	//약식경로 : _C를 붙이지 않아도된다

	if(pawnClass.Succeeded())
		DefaultPawnClass = pawnClass.Class;
}