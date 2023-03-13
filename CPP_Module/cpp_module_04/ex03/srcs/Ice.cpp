#include "../incs/Ice.hpp"
#include <iostream>

Ice::Ice(void): AMateria("ice") {}
Ice::Ice(const std::string &type): AMateria(type) {}
Ice::Ice(const Ice &ref) { (*this) = ref; }
Ice::~Ice(void) {}

Ice	&Ice::operator=(const Ice &ref) {
	if (this != &ref) {
		this->_type = ref._type;
		this->_xp = ref._xp;
	}
	return (*this);
}

// Utils
AMateria	*Ice::clone(void) const { return (new Ice(*this)); }

void		Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	AMateria::use(target);
}