#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Property.generated.h" //.generated.h �� ���� �ؿ� �־���Ѵ�

UCLASS()
class U04_CPP_BASICSYNTAX_API AC01_Property : public AActor
{
	GENERATED_BODY() //class���ο��� �̰ź��� �ڵ尡 ���� ������ �ȵȴ�
	
public:	
	AC01_Property();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
