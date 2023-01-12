#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_BoxBase.h"
#include "C14_ExplosionTrigger.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API AC14_ExplosionTrigger : public AC00_BoxBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
