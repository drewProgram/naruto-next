// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemInterface.h"
#include "Abilities/NNAbilitySystemComponent.h"
#include "Abilities/BaseAttributeSet.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class NARUTONEXT_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Abilities")
	UNNAbilitySystemComponent* AbilitySystem;

	UPROPERTY()
	const UBaseAttributeSet* AttributeSet;

private:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationRate;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	 UFUNCTION(BlueprintCallable)
	 void GrantAbility(TSubclassOf<class UGameplayAbility> AbilityClass, int32 Level, int32 InputCode);

	 UFUNCTION(BlueprintCallable)
	 void ActivateAbility(int32 InputCode);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MoveForward(float AxisValue);

	void MoveRight(float AxisValue);
};
