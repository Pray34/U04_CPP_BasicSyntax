#pragma once

#include "CoreMinimal.h"
#include "04_Collision/C00_BoxBase.h"
#include "C10_BlueprintOverride.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API AC10_BlueprintOverride : public AC00_BoxBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	UFUNCTION(BlueprintImplementableEvent) //B.I Event가 붙은 함수들은 cpp에 몸체를 구현하면 안된다
		void SetBodyColor();

	UFUNCTION(BlueprintNativeEvent)
		void ResetBodyColor();
};
