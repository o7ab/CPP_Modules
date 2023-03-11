#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}
Cat::Cat(Cat const & src) : Animal()
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}
Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(Cat const & copy)
{
	if (this != &copy)
	{	
		delete this->brain;
		this->type = copy.getType();
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}
void Cat::makeSound() const{
	std::cout << "Cat sound" << std::endl;
}
Brain *Cat::getBrain() const
{
	return this->brain;
}
