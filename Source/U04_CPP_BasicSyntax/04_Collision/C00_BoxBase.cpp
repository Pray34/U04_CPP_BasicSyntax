#include "C00_BoxBase.h"
#include "Components/BoxComponent.h"

AC00_BoxBase::AC00_BoxBase()
{
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(Scene);
}