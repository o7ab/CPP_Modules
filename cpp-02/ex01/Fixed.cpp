#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixedPointValue = rhs.getRawBits();
	return *this;
}
int Fixed::getRawBits(void) const
{
	return this->fixedPointValue;
}
void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}
Fixed::Fixed(const int & src)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = src << this->fractionalBits;
}
Fixed::Fixed(const float & src)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(src * (1 << this->fractionalBits));
}
float Fixed::toFloat(void) const
{
	return (float)this->fixedPointValue / (1 << this->fractionalBits);
}
int Fixed::toInt(void) const
{
	return this->fixedPointValue >> this->fractionalBits;
}

std::ostream & operator << (std::ostream &out, const Fixed &c)
{
    out << c.toFloat();
    return out;
}