#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}
Dog::Dog(Dog const & src){
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = src;
}
Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(Dog const & copy){

	this->type = copy.getType();
	this->brain = new Brain();
	return *this;
}
void Dog::makeSound() const{
	std::cout << "Dog sound" << std::endl;
}
