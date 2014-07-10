#pragma once

#include "GameFramework/Actor.h"
#include "GeneratedMeshComponent.h"
#include "Cube.generated.h"

/**
*
*/
UCLASS()
class ACube : public AActor
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GameGeneratedActor")
	void SetBox(const float& Size, const FVector& Position);

	UPROPERTY(BlueprintReadOnly, Category = "GameGeneratedActor")
	TSubobjectPtr<UGeneratedMeshComponent> Mesh;

};