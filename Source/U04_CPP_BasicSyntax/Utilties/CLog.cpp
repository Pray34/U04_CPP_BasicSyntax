#include "CLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(GameProject, Error, All) //GameProject 카테고리를 생성

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
	UE_LOG(GameProject, Error, L"%d", InValue); // GameProject 카테고리를 위에서 생성
	//LogTemp : 언리얼 로그 카테고리에서 제일 요긴하게 쓸수있음
}

void CLog::Log(float InValue)
{
	UE_LOG(GameProject, Error, L"%f", InValue);
}

void CLog::Log(const FString& InValue)
{
	UE_LOG(GameProject, Error, L"%s", *InValue); //언리얼 FString 은 *를 붙여 변환
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
	if (!!InValue) // !! : 언리얼 문법(not null 과 똑같은 의미)
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
