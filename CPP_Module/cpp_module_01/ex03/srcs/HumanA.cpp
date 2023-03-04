#include "../incs/HumanA.hpp"
#include <iostream>

HumanA::HumanA(void) { this->_weapon = NULL; this->_name = std::string(); }
HumanA::HumanA(const std::string &name, Weapon &weapon) {
	this->_weapon = &weapon;
	this->_name = std::string(name.c_str());
}
HumanA::HumanA(const HumanA &humanA) { (*this) = humanA; }
HumanA::~HumanA(void) {}

HumanA	&HumanA::operator=(const HumanA &humanA) {
	if (this != &humanA) {
		this->_weapon = humanA._weapon;
		this->_name = std::string(humanA._name.c_str());
	}
	return (*this);
}

// Utils
bool	HumanA::attack(void) {
	if (this->_weapon == NULL) {
		std::cerr << "Error: HumanA [" << this->_name << "] has no weapon\n";
	} else {
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '\n';
	}
	return (true);
}

bool	HumanA::setWeapon(Weapon &weapon) { this->_weapon = &weapon; return (true); }