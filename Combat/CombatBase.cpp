#include "CombatBase.h"
#include <iostream>

bool Combat::Entity::DealPhysicalDmg(int dmg)
{
    //I need to be alive
    if (hp < 0)
        return false;
    //If my defense is negative, increase dmg
    //If my defense is positive, decrease dmg
    if (this->defense > 0)
    {
        hp -= (float)dmg / defense;
    }
    else if (this->defense < 0)
    {
        hp -= (float)dmg * -defense;
    }
    else
    {
        hp -= float(dmg);
    }

    return true;
}

bool Combat::Entity::DealMagicalDmg(int dmg)
{
    //I need to be alive
    if (hp < 0)
        return false;
    //If my defense is negative, increase dmg
    //If my defense is positive, decrease dmg
    if (this->magic_defense > 0)
    {
        hp -= (float)dmg / magic_defense;
    }
    else if (this->magic_defense < 0)
    {
        hp -= (float)dmg * -magic_defense;
    }
    else
    {
        hp -= float(dmg);
    }

    return true;
}

bool Combat::Weapon::Attack(Entity* ent) const
{
    std::cout << "Attacked with " << damage << std::endl;
    return true;
}

bool Combat::Weapon::Attack() const
{
    Attack(nullptr);

    return true;
}
