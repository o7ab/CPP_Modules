#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	// (void) src;
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const float & src)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(src * (1 << this->fractionalBits));
}
Fixed::Fixed(const int & src)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = src << this->fractionalBits;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

Fixed & Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->fixedPointValue = rhs.getRawBits();
	return *this;
}
bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}
bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}
bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}
bool	Fixed::operator<(Fixed const & rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}
bool	Fixed::operator>(Fixed const & rhs) const
{
	return (getRawBits() > rhs.getRawBits());
}
bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}
std::ostream & operator << (std::ostream &out, const Fixed &c)
{
    out << c.toFloat();
    return out;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int Fixed::getRawBits(void) const
{
	return fixedPointValue;
}
void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
}
float Fixed::toFloat(void) const
{
	return (float)this->fixedPointValue / (1 << this->fractionalBits);
}
int Fixed::toInt(void) const
{
	return this->fixedPointValue >> this->fractionalBits;
}

Fixed Fixed::operator-(Fixed const & rhs)
{
	Fixed tmp;
	tmp.setRawBits(-rhs.getRawBits());
	return tmp;
}
Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed tmp;
	tmp.setRawBits(tmp.getRawBits() + rhs.getRawBits());
	return tmp;
}
Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed tmp;
	tmp.setRawBits(tmp.getRawBits() / rhs.getRawBits());
	return tmp;
}
Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed tmp (this->toFloat() * rhs.toFloat());
	// std::cout << "operator * called " << this->getRawBits() << " , " << rhs.getRawBits()<<std::endl;
	// tmp.setRawBits(this->getRawBits() * rhs.getRawBits());
	// std::cout << tmp.fixedPointValue << std::endl;
	return tmp;
}
Fixed	&Fixed::operator++(void)
{
	this->fixedPointValue++;
	return *this;
}
Fixed	&Fixed::operator--(void)
{
	this->fixedPointValue--;
	return *this;
}
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed & Fixed::min(Fixed  &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return lhs;
	else 
		return rhs;
}
Fixed & Fixed::max(Fixed  &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	else 
		return rhs;
}
const Fixed & Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return lhs;
	else 
		return rhs;
}
const Fixed & Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	else 
		return rhs;
}