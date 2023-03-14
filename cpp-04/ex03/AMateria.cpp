#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
}

AMateria::AMateria(AMateria const & src) {
	this->type = src.type;
}

AMateria::~AMateria(void) {
}

AMateria &	AMateria::operator=(AMateria const & rhs) {
	(void)rhs;
	return *this;
}

std::string const &	AMateria::getType(void) const {
	return this->type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Materia use called on " << this->type << " with target " << target.getName() << std::endl;
}
