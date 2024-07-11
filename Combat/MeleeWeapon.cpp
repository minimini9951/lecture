#include "MeleeWeapon.h"
#include <iostream>

bool Combat::Melee::Attack()
{
    std::cout << "Attacked with Melee" << std::endl;
    Entity* ent = nullptr;

    //ent = FineEnemyInRange(range, x, y);

    return PhysicalWeapon::Attack(ent);
}
