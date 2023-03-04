#include "../incs/HumanB.hpp"
#include <iostream>

HumanB::HumanB(void) { this->_weapon = NULL; this->_name = std::string(); }
HumanB::HumanB(const std::string &name) {
	this->_weapon = NULL;
	this->_name = std::string(name.c_str());
}
HumanB::HumanB(const std::string &name, Weapon &weapon) {
	this->_weapon = &weapon;
	this->_name = std::string(name.c_str());
}
HumanB::HumanB(const HumanB &humanB) { (*this) = humanB; }
HumanB::~HumanB(void) {}

HumanB	&HumanB::operator=(const HumanB &humanB) {
	if (this != &humanB) {
		this->_weapon = humanB._weapon;
		this->_name = std::string(humanB._name.c_str());
	}
	return (*this);
}

// Utils
bool	HumanB::attack(void) {
	if (this->_weapon == NULL) {
		std::cout << "HumanB [" << this->_name << "] has no weapon\n";
	} else {
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '\n';
	}
	return (true);
}

bool	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	return (true);
}