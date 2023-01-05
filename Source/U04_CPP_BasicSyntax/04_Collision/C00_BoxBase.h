#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_TextRenderBase.h"
#include "C00_BoxBase.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API AC00_BoxBase : public AC00_TextRenderBase
{
	GENERATED_BODY()
	
public:
	AC00_BoxBase();

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;
};
