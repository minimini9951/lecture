#pragma once
#include "PhysicalWeapon.h"

namespace Combat
{
	class Melee : public PhysicalWeapon
	{
		float range;
	public:
		bool Attack();
	};
}