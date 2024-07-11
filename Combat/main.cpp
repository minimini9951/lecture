#include "RangeWeapon.h"
#include "MeleeWeapon.h"
#include "MagicalWeapon.h"

int main()
{
	Combat::RangedWeapon bow;
	Combat::Melee sword;
	Combat::MagicWeapon magic;

	Combat::Entity player;

	bow.Attack();
	sword.Attack();
	magic.Attack(nullptr);

	player.myWeapon = &sword;
	player.myWeapon->Attack();

	return 0;
}