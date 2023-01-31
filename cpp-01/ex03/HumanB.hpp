#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapons.hpp"

class HumanB{
	private:
		std::string name;
		Weapons *weapon;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapons &Pweapon);
};

#endif