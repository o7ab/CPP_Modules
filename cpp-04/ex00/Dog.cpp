#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
}
Dog::Dog(Dog const & src){
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = src;
}
Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(Dog const & copy){
	this->type = copy.getType();
	return *this;
}
void Dog::makeSound() const{
	std::cout << "Dog sound" << std::endl;
}
