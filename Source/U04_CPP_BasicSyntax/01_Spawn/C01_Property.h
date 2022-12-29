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

private:
	UPROPERTY(EditAnywhere)
		int Alpha = 10;
	UPROPERTY(EditInstanceOnly)//Instance : 객체생성시(world)
		int Bravo = 20;
	UPROPERTY(EditDefaultsOnly)//Defaluts : class 내부에서만
		int Chalie;

	UPROPERTY(VisibleAnywhere) //Visible : 읽기전용
		int Delta = 40;
	

	UPROPERTY(EditDefaultsOnly, Category = "Visible")
		bool BVisible = true;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly) //Blueprint : private에서 불가능 //ReadOnly : Get만 가능
		int Echo = 50;
	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly) //ReadWrite : Get,Set 가능
		int Foxtrot = 60;

private:
	int Golf = 70;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
};
