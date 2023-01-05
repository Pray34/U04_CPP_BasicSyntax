#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C00_TextRenderBase.generated.h"


//AC00_TextRenderBase Class는 공통된 기능을 만들기 위한 부모 class
//자세한 기능들은 자식에서 구현
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
