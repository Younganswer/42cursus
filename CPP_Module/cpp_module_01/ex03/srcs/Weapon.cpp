#include "../incs/Weapon.hpp"

Weapon::Weapon(void): _type(std::string()) {}
Weapon::Weapon(const std::string &type): _type(type) {}
Weapon::Weapon(const Weapon &weapon): _type(weapon._type) {}
Weapon::~Weapon(void) {}

Weapon	&Weapon::operator=(const Weapon &weapon) {
	if (this != &weapon) {
		this->~Weapon();
		new (this) Weapon(weapon);
	}
	return (*this);
}

// Getter
std::string			Weapon::getType(void) { return (this->_type); }
const std::string	&Weapon::getType(void) const { return (this->_type); }

// Setter
bool		Weapon::setType(const std::string &type) {
	this->_type = std::string(type.c_str());
	return (true);
}