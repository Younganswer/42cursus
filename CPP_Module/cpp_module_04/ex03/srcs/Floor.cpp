#include "../incs/Floor.hpp"

Floor::Floor(void): _count(0) {
	for (int i=0; i<1024; i++) {
		this->_materia[i] = NULL;
	}
}
Floor::Floor(const Floor &ref): _count(ref._count) {
	for (size_t i=0; i<this->_count; i++) {
		this->_materia[i] = ref._materia[i]->clone();
	}
}
Floor::~Floor() {
	for (size_t i=0; i<this->_count; i++) {
		if (this->_materia[i]->getEquipped() == false) {
			delete this->_materia[i];
		}
	}
}

Floor& Floor::operator=(const Floor &rhs) {
	(void) rhs;
	return (*this);
}

//	Getter
AMateria* Floor::getMateria(size_t idx) const {
	if (idx < 0 || this->_count <= idx) {
		return (NULL);
	}
	return (this->_materia[idx]);
}

//	Setter
void Floor::setMateria(AMateria *materia) {
	if (1024 <= this->_count) {
		return ;
	}
	_materia[(this->_count)++] = materia;
}