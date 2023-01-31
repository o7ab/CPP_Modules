#include "Weapons.hpp"

Weapons::Weapons()
{
}

Weapons::Weapons(std::string type)
{
	this->type = type;
}

Weapons::~Weapons()
{
}

void	Weapons::setType(std::string type)
{
	this->type = type;
}

std::string	Weapons::getType()
{
	return (this->type);
}