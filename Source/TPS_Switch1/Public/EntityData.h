#pragma once

#include "CoreMinimal.h"
#include "EntityData.generated.h"

USTRUCT(BlueprintType)
struct TPS_SWITCH1_API FEntityData
{
	GENERATED_BODY()

public:
	FEntityData();

	UPROPERTY(Category = FEntityData, EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* Color;
};
