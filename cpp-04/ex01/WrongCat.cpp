# include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}
WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}
WrongCat &WrongCat::operator=(WrongCat const & copy)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	this->type = copy.type;
	return *this;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}