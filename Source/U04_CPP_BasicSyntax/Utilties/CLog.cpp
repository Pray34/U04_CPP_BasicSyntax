#include "CLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(GameProject, Error, All) //GameProject ī�װ��� ����

void CLog::Print(const FString& InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue);
}

void CLog::Print(int32 InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, FString::FromInt(InValue));
}

void CLog::Print(float InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, FString::SanitizeFloat(InValue));
}

void CLog::Print(const FVector& InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue.ToString());
}

void CLog::Print(const FRotator& InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue.ToString());
}

void CLog::Log(int32 InValue)
{
	UE_LOG(GameProject, Error, L"%d", InValue); // GameProject ī�װ��� ������ ����
	//LogTemp : �𸮾� �α� ī�װ����� ���� ����ϰ� ��������
}

void CLog::Log(float InValue)
{
	UE_LOG(GameProject, Error, L"%f", InValue);
}

void CLog::Log(const FString& InValue)
{
	UE_LOG(GameProject, Error, L"%s", *InValue); //�𸮾� FString �� *�� �ٿ� ��ȯ
}

void CLog::Log(const FVector& InValue)
{
	UE_LOG(GameProject, Error, L"%s", *InValue.ToString());
}

void CLog::Log(const FRotator& InValue)
{
	UE_LOG(GameProject, Error, L"%s", *InValue.ToString());
}

void CLog::Log(const UObject* InValue)
{
	FString str;
	if (!!InValue) // !! : �𸮾� ����(not null �� �Ȱ��� �ǹ�)
		str.Append(InValue->GetName());

	str.Append(!!InValue ? " is not null" : " NULL");

	UE_LOG(GameProject, Error, L"%s", *str);
}

void CLog::Log(const FString& InFuncName, int32 InLineNumber)
{
	FString str;
	str.Append(InFuncName);
	str.Append(", ");
	str.Append(FString::FromInt(InLineNumber));
	UE_LOG(GameProject, Error, L"%s", *str);
}
