#pragma once
#include "CombatBase.h"

namespace Combat
{
	//MagicWeapon deals Magic dmg
	class MagicWeapon : public Weapon
	{
	//protected:
	public:
		bool Attack(Entity* ent);
	};
}
