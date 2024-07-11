#include "PhysicalWeapon.h"

bool Combat::PhysicalWeapon::Attack(Entity* ent) const
{
    Weapon::Attack(ent);

    if (ent == nullptr)
        return false;

    ent->DealPhysicalDmg(GetDamage());

    return true;
}
