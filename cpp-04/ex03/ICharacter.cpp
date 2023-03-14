#include "ICharacter.hpp"

std::string const &	ICharacter::getName(void) const {
	return (this->name);
}

void	ICharacter::equip(AMateria* m) {
	if (this->materia_count < 4) {
		this->materia[this->materia_count] = m;
		this->materia_count++;
	}
}

void	ICharacter::unequip(int idx) {
	if (idx >= 0 && idx < this->materia_count) {
		this->materia[idx] = NULL;
		this->materia_count--;
	}
}

void	ICharacter::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < this->materia_count) {
		this->materia[idx]->use(target);
	}
}