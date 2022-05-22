// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Sasuke.h"

ASasuke::ASasuke()
{
}

void ASasuke::BeginPlay()
{
	Super::BeginPlay();
}

void ASasuke::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("Chakra value: %f"), AttributeSet->GetChakra());
}