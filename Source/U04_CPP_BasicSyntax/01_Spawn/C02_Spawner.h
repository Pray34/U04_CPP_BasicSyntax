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
		UClass* ClassRef;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_StaticMesh> TsubclassRef;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_StaticMesh> SpawnClasses[4];

private:
	class AC02_StaticMesh* Meshes[4];

};
