#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal const & copy)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->type = copy.type;
	return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
std::string WrongAnimal::getType() const
{
	return this->type;
}
void WrongAnimal::setType(std::string type)
{
	this->type = type;
}