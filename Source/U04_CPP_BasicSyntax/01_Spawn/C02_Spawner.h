#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_Spawner.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API AC02_Spawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AC02_Spawner();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
		UClass* ClassRef; //UClass : 언리얼의 모든 class를 가져옴

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_StaticMesh> TsubclassRef;
	//TSubclassOf : 특정 클래스를 가져옴 // <> 안에다 클래스 정의

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_StaticMesh> SpawnClasses[4]; //멤버변수는 대문자로 시작

private:
	class AC02_StaticMesh* Meshes[4];

};
