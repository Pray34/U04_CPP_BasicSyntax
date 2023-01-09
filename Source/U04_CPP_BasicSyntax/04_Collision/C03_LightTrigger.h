#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_BoxBase.h"
#include "C03_LightTrigger.generated.h"

DECLARE_DELEGATE(FBoxBeginOverlap); //void __()
DECLARE_DELEGATE(FBoxEndOverlap);
DECLARE_DELEGATE_RetVal_OneParam(FString, FBoxBeginRandomLightColor, FLinearColor);


UCLASS()
class U04_CPP_BASICSYNTAX_API AC03_LightTrigger : public AC00_BoxBase
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FBoxBeginOverlap OnBoxBeginOverlap; //Delegate 변수는 public에다 만드는게 일반적이다
	FBoxEndOverlap OnBoxEndOverlap;
	FBoxBeginRandomLightColor OnBoxBeginRandomLightColor;
};
