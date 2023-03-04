#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hp = 100;
	this->energy = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = fragTrap;
}
FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->name = fragTrap.name;
	this->hp = fragTrap.hp;
	this->energy = fragTrap.energy;
	this->attackDamage = fragTrap.attackDamage;
	return *this;
}
void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name << " gave high fives for everyone!" << std::endl;
}
