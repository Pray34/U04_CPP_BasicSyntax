#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Property.generated.h" //.generated.h 가 제일 밑에 있어야한다

UCLASS()
class U04_CPP_BASICSYNTAX_API AC01_Property : public AActor
{
	GENERATED_BODY() //class내부에서 이거보다 코드가 위에 있으면 안된다
	
public:	
	AC01_Property();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
