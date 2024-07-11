#pragma once

namespace Combat
{
	class Weapon;
	class Entity;
	//Design
	//What is the system doing

	//3 types of weapons
	// Physical
		//Ranged
		//Melee
	// Magic
		//Magic
	// Healer

	//4 types of weapons
		//Ranged
		//Melee
		//Magic
		//Healer

	//A way to handle all of them
	//The player / Enemy will have 1 equiped weapon

	class Entity
	{
	protected:
		//Stats
		float Maxhp;
		float hp;
		int defense;
		int attack;
		int magic_attack;
		int magic_defense;
		int healPower;
		//
		//Position
		float x;
		float y;
		// 

	public:

		Weapon* myWeapon;
		bool DealPhysicalDmg(int dmg);
		bool DealMagicalDmg(int dmg);
	};

	class Weapon
	{
		int damage;
		//name
		//Stats needed

	protected:
		bool Attack(Entity* ent) const;

	public:
		bool Attack() const;
		int GetDamage() const { return damage; }
	};
}