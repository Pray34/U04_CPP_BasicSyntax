#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_BoxBase.h"
#include "C08_EventTrigger.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API AC08_EventTrigger : public AC00_BoxBase
{
	GENERATED_BODY()
	
public:
	DECLARE_EVENT_OneParam(AC08_EventTrigger, FDelegate, int32);

	FDelegate OnDelegate;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
