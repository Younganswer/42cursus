#include "../incs/HumanB.hpp"
#include <iostream>

HumanB::HumanB(void): _weapon(NULL), _name(std::string()) {}
HumanB::HumanB(const std::string &name): _weapon(NULL), _name(name.c_str()) {}
HumanB::HumanB(const std::string &name, Weapon &weapon): _weapon(&weapon), _name(name.c_str()) {}
HumanB::~HumanB(void) {}

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