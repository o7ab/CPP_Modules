#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}
Cat::Cat(Cat const & src){
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = src;
}
Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(Cat const & copy){
	this->type = copy.getType();
	return *this;
}
void Cat::makeSound() const{
	std::cout << "Cat sound" << std::endl;
}