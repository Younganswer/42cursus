#include "../incs/Cure.hpp"
#include <iostream>

Cure::Cure(void): AMateria("cure") {}
Cure::Cure(const Cure &ref) { (*this) = ref; }
Cure::~Cure(void) {}

Cure	&Cure::operator=(const Cure &ref) {
	if (this != &ref) {
		this->_type = ref._type;
		this->_xp = ref._xp;
	}
	return (*this);
}

// Utils
AMateria	*Cure::clone(void) const { return (new Cure(*this)); }

void		Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	AMateria::use(target);
}