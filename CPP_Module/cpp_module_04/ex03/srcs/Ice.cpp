#include "../incs/Ice.hpp"
#include <iostream>

Ice::Ice(void): AMateria("ice") {}
Ice::Ice(const std::string &type): AMateria(type) {}
Ice::Ice(const Ice &ref): AMateria(ref) {}
Ice::~Ice(void) {}

Ice	&Ice::operator=(const Ice &rhs) {
	if (this != &rhs) {
		this->~Ice();
		new (this) Ice(rhs);
	}
	return (*this);
}

// Utils
AMateria	*Ice::clone(void) const { return (new Ice(*this)); }

void		Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	AMateria::use(target);
}