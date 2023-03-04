#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->attackDamage = 20;
}
ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = rhs.name;
	this->hp = rhs.hp;
	this->energy = rhs.energy;
	this->attackDamage = rhs.attackDamage;
	return *this;
}
void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}