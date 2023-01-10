#include "C07_SpotLights.h"
#include "Global.h"
#include "C05_MultiTrigger.h"
#include "Components/SpotLightComponent.h"


AC07_SpotLights::AC07_SpotLights()
{
	for (int32 i = 0; i < 3; i++)
	{
		FString name;
		name.Append("SpotLight");
		name.Append(FString::FromInt(i + 1));
		SpotLights[i] = CreateDefaultSubobject<USpotLightComponent>(FName(*name));
		SpotLights[i]->SetupAttachment(Scene);
		SpotLights[i]->SetRelativeLocation(FVector(0, i * 200, 0));
		SpotLights[i]->Intensity = 1e+5f;
		SpotLights[i]->OuterConeAngle = 25.f;
		SpotLights[i]->SetRelativeRotation(FQuat(FRotator(-90.0f, 0, 0)));
	}
}

void AC07_SpotLights::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC05_MultiTrigger::StaticClass(), actors);
	if (actors.Num() < 1) return; //nullcheck

	AC05_MultiTrigger* multiTrigger = Cast<AC05_MultiTrigger>(actors[0]);
	if (!multiTrigger) return; //nullcheck

	multiTrigger->OnMultiBeginOverlap.AddUFunction(this, "OnRandomLightColor");
}

void AC07_SpotLights::OnRandomLightColor(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
		SpotLights[i]->SetLightColor(FLinearColor(1, 1, 1));

	SpotLights[InIndex]->SetLightColor(InColor);
}
