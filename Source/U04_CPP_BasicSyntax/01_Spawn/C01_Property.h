#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Property.generated.h" //.generated.h �� ���� �ؿ� �־���Ѵ�

UCLASS()
class U04_CPP_BASICSYNTAX_API AC01_Property : public AActor
{
	GENERATED_BODY() //class���ο��� �̰ź��� �ڵ尡 ���� ������ �ȵȴ�
	
public:	
	AC01_Property();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		int Alpha = 10;
	UPROPERTY(EditInstanceOnly)//Instance : ��ü������(world)
		int Bravo = 20;
	UPROPERTY(EditDefaultsOnly)//Defaluts : class ���ο�����
		int Chalie;

	UPROPERTY(VisibleAnywhere) //Visible : �б�����
		int Delta = 40;
	

	UPROPERTY(EditDefaultsOnly, Category = "Visible")
		bool BVisible = true;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly) //Blueprint : private���� �Ұ��� //ReadOnly : Get�� ����
		int Echo = 50;
	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly) //ReadWrite : Get,Set ����
		int Foxtrot = 60;

private:
	int Golf = 70;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
};
