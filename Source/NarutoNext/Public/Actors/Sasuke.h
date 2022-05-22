// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Sasuke.generated.h"

/**
 * 
 */
UCLASS()
class NARUTONEXT_API ASasuke : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ASasuke();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
};
