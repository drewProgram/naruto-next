// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

 #include "Abilities/GameplayAbility.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
	: RotationRate(10.f)
{    
	PrimaryActorTick.bCanEverTick = true;

	// Ability related init
	AbilitySystem = CreateDefaultSubobject<UNNAbilitySystemComponent>(TEXT("AbilitySystem"));
	AbilitySystem->SetIsReplicated(true);

	// Camera related init
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilitySystem))
	{
		AttributeSet = AbilitySystem->GetSet<UBaseAttributeSet>();
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

void ABaseCharacter::GrantAbility(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputCode)
{
	if (GetLocalRole() == ROLE_Authority && IsValid(AbilitySystem) && IsValid(AbilityClass))
	{
		UGameplayAbility* Ability = AbilityClass->GetDefaultObject<UGameplayAbility>();

		if (IsValid(Ability))
		{
			// Create the new ability spec struct
			FGameplayAbilitySpec AbilitySpec(
				Ability,
				Level,
				InputCode
			);

			AbilitySystem->GiveAbility(AbilitySpec);
		}
	}
}

void ABaseCharacter::ActivateAbility(int32 InputCode)
{
	if (IsValid(AbilitySystem))
	{
		AbilitySystem->AbilityLocalInputPressed(InputCode);
	}
}

void ABaseCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ABaseCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

