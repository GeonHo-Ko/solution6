// Fill out your copyright notice in the Description page of Project Settings.

#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Wedge_B.Shape_Wedge_B"));
    if (MeshAsset.Succeeded())
    {
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel"));
    if (MaterialAsset.Succeeded())
    {
        StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
    }
}

void ARotatingPlatform::BeginPlay()
{
    Super::BeginPlay();
}

void ARotatingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += RotationSpeed * DeltaTime;
    SetActorRotation(NewRotation);
}