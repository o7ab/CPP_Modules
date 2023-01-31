#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapons.hpp"

class HumanA{
	private:
		std::string name;
		Weapons &weapon;
	public:
		HumanA(std::string name, Weapons &Pweapon);
		~HumanA();
		void attack();
};

#endif