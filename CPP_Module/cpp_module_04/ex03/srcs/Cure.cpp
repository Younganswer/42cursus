#include "../incs/Cure.hpp"
#include <iostream>

Cure::Cure(void): AMateria("cure") {}
Cure::Cure(const Cure &ref): AMateria(ref) {}
Cure::~Cure(void) {}

Cure	&Cure::operator=(const Cure &rhs) {
	if (this != &rhs) {
		this->~Cure();
		new (this) Cure(rhs);
	}
	return (*this);
}

// Utils
AMateria	*Cure::clone(void) const { return (new Cure(*this)); }

void		Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	AMateria::use(target);
}