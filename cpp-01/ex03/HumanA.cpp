#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapons &Pweapon) : name(name), weapon(Pweapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}