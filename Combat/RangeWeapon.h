#pragma once
#include "PhysicalWeapon.h"

namespace Combat
{
	class RangedWeapon : public PhysicalWeapon
	{
		//ammo
		//Max ammo
		int Ammo;
		int MaxAmmo;

		//shoot dir
		float xDir;
		float yDir;

	public:
		//AttackFn checks for dir of shoot
		bool Attack(float x, float y);
		void Reload();
	};
}