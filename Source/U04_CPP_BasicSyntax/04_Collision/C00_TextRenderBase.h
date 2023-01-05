#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C00_TextRenderBase.generated.h"


//AC00_TextRenderBase Class�� ����� ����� ����� ���� �θ� class
//�ڼ��� ��ɵ��� �ڽĿ��� ����
UCLASS() 
class U04_CPP_BASICSYNTAX_API AC00_TextRenderBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AC00_TextRenderBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
};
