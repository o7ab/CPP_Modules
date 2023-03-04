# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(10), energy(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), attackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = clapTrap.name;
	this->hp = clapTrap.hp;
	this->energy = clapTrap.energy;
	this->attackDamage = clapTrap.attackDamage;
	return *this;
}
void ClapTrap::attack(std::string const &target) {
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap is too broken to attack..." << std::endl;
		return ;
	}
	else if (this->energy <=  0)
	{
		std::cout << "ClapTrap is too tired to attack..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energy -= 1;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap is already dead..." << std::endl;
		return ;
	}
	if (amount > (unsigned)this->hp)
		amount = this->hp;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hp -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy <=  0)
	{
		std::cout << "ClapTrap is too tired to be repaired..." << std::endl;
		return ;
	}
	if (amount + this->hp > 10)
		amount = 10 - this->hp;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	this->hp += amount;
	this->energy -= 1;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	this->attackDamage = attackDamage;
}
int ClapTrap::getAttackDamage(void) {
	return attackDamage;
}