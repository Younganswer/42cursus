#include "../incs/Floor.hpp"

Floor::Floor(void) {
	this->_count = 0;
	for (int i=0; i<1024; i++) {
		this->_materia[i] = NULL;
	}
}
Floor::Floor(const Floor &ref) { (*this) = ref; }
Floor::~Floor() {
	for (size_t i=0; i<this->_count; i++) {
		if (this->_materia[i]->getEquipped() == false) {
			delete this->_materia[i];
		}
	}
}

Floor& Floor::operator=(const Floor &ref) {
	(void) ref;
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