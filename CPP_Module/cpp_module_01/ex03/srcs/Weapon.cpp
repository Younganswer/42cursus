#include "../incs/Weapon.hpp"

Weapon::Weapon(void) { this->_type = std::string(); }
Weapon::Weapon(const std::string &type) { this->_type = std::string(type.c_str()); }
Weapon::Weapon(const Weapon &weapon) { *this = weapon; }
Weapon::~Weapon(void) {}

Weapon	&Weapon::operator=(const Weapon &weapon) {
	if (this != &weapon) {
		this->_type = std::string(weapon._type.c_str());
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