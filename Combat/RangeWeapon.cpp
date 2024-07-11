#include "RangeWeapon.h"
#include <iostream>

bool Combat::RangedWeapon::Attack(float x, float y)
{
    if (Ammo < 0)
        return false;

    Ammo--;
    //find if there is an ent in the next N units in my dir, from my pos
    std::cout << "Attacked with Range" << std::endl;

    Entity* ent = nullptr;

    //ent = FindClosestEntity(x, y, xDir, yDir);

    return PhysicalWeapon::Attack(ent);;
}

void Combat::RangedWeapon::Reload()
{
    Ammo = MaxAmmo;
}
