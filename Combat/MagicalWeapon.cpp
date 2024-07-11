#include "MagicalWeapon.h"
#include <iostream>

bool Combat::MagicWeapon::Attack(Entity* ent)
{
    std::cout << "Attacked with Magic" << std::endl;
    Weapon::Attack(ent);

    ent->DealMagicalDmg(GetDamage());

    return true;
}
