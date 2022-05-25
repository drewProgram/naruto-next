#pragma once

#include "CharacterData.generated.h"

UENUM(BlueprintType)
enum class ECharacterAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Fireball,
	Melee
};
