#include "Character.hpp"

Character::Character(void) : ICharacter(){
	this->materia_count = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

Character::Character(std::string const & name) : ICharacter() {
	this->name = name;
	this->materia_count = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

Character::Character(Character const & src) : ICharacter(src){
	this->materia_count = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	*this = src;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++)
		if (this->materia[i])
			delete this->materia[i];
}

Character &	Character::operator=(Character const & rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
			if (this->materia[i])
				delete this->materia[i];
		for (int i = 0; i < 4; i++)
			if (rhs.materia[i])
				this->materia[i] = rhs.materia[i]->clone();
	}
	return *this;
}

std::string const &	Character::getName(void) const {
	return this->name;
}

void	Character::equip(AMateria* m) {
	if (this->materia_count < 4 && m) {
		this->materia[this->materia_count] = m;
		this->materia_count++;
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->materia[idx]) {
		this->materia[idx] = NULL;
		this->materia_count--;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->materia[idx])
		this->materia[idx]->use(target);
}

