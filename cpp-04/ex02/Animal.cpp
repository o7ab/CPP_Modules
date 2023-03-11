#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(Animal const & src){
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = src;
}
Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}
Animal &Animal::operator=(Animal const & copy){
	this->type = copy.getType();
	return *this;
}
std::string Animal::getType() const
{
	return this->type;
}
