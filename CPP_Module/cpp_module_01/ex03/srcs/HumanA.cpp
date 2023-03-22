#include "../incs/HumanA.hpp"
#include <iostream>

HumanA::HumanA(void): _weapon(NULL), _name(std::string()) {}
HumanA::HumanA(const std::string &name, Weapon &weapon): _weapon(&weapon), _name(name) {}
HumanA::HumanA(const HumanA &humanA): _weapon(humanA._weapon), _name(humanA._name()) {}
HumanA::~HumanA(void) {}

HumanA	&HumanA::operator=(const HumanA &humanA) {
	if (this != &humanA) {
		this->~HumanA();
		new (this) HumanA(humanA);
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