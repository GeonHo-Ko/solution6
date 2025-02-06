// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SOLUTION6_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

private:
	UPROPERTY(EditAnywhere, Category = "Platform Settings")
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Platform Settings")
	float MaxRange = 300.0f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;

	FVector StartLocation;
	FVector Direction = FVector(1, 0, 0);

};
