#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_BoxBase.h"
#include "C01_ActorOverlap.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API AC01_ActorOverlap : public AC00_BoxBase
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
