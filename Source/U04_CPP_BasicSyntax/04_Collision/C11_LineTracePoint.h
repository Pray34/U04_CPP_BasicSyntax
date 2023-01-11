#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_TextRenderBase.h"
#include "C11_LineTracePoint.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API AC11_LineTracePoint : public AC00_TextRenderBase
{
	GENERATED_BODY()
	
public:
	AC11_LineTracePoint();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;
};
