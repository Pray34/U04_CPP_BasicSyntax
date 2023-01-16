#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRifle.generated.h"

UCLASS()
class U04_CPP_BASICSYNTAX_API ACRifle : public AActor
{
	GENERATED_BODY()
	
public:	
	ACRifle();

	static ACRifle* Spawn(class UWorld* InWorld, class ACharacter* InOwnerCharacter);

	FORCEINLINE bool IsEquipped() { return bEquipped; }
	FORCEINLINE bool IsEquipping() { return bEquipping; }

	void Equip();
	void UnEquip();
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HolsterSocket = "Holster_Rifle";
	
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HandSocket = "Hand_Rifle";

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* GrabMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		class UAnimMontage* UnGrabMontage;
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USkeletalMeshComponent* Mesh;

	class ACharacter* OwnerCharacter;

	bool bEquipped; //true : OnRifle
	bool bEquipping; //true : PlayMontage
	//소켓에 어타치
};
