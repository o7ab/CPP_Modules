#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}
Dog::Dog(Dog const & src) : Animal()
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}
Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const & copy)
{
	if (this != &copy)
	{	
		delete this->brain;
		this->type = copy.getType();
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Dog sound" << std::endl;
}
Brain *Dog::getBrain() const
{
	return this->brain;
}