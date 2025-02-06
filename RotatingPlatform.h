// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class SOLUTION6_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

private:
	UPROPERTY(EditAnywhere, Category = "Platform Settings")
	float RotationSpeed = 30.0f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;

};
