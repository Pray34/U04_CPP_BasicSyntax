#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_BoxBase.h"
#include "C05_MultiTrigger.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiBeginOverlap, int32, FLinearColor);

UCLASS()
class U04_CPP_BASICSYNTAX_API AC05_MultiTrigger : public AC00_BoxBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FMultiBeginOverlap OnMultiBeginOverlap;
};