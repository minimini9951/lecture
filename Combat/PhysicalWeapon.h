#pragma once
#include "CombatBase.h"

namespace Combat
{
	//Physical weapon deals physical dmg
	class PhysicalWeapon : public Weapon
	{
	protected:
		float x;
		float y;

		bool Attack(Entity* ent) const;
	};
}