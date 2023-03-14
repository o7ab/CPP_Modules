#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	for (int i = 0; i < 4; i++)
		this->materia[i] = src.materia[i]->clone();
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete this->materia[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++)
			this->materia[i] = rhs.materia[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->materia[i] == NULL) {
			this->materia[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->materia[i] != NULL && this->materia[i]->getType() == type)
			return this->materia[i]->clone();
	}
	return NULL;
}
