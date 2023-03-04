#include "../incs/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void): ClapTrap() {
	std::cout << "Default constructor of FR4G-TP is called" << '\n';
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
	std::cout << "const std::string constructor of FR4G-TP is called" << '\n';
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &Frag_trap) {
	std::cout << "Copy constructor of FR4G-TP is called" << '\n';
	(*this) = Frag_trap;
}

FragTrap	&FragTrap::operator=(const FragTrap &Frag_trap) {
	std::cout << "Copy assign operator of FR4G-TP is called" << '\n';
	if (this != &Frag_trap) {
		ClapTrap::operator=(Frag_trap);
	}
	return (*this);
}

FragTrap::~FragTrap(void) { std::cout << "Destructor of FR4G-TP is called" << '\n'; }

// Util
void	FragTrap::highFivesGuys(void) {
	std::cout << "FR4G-TP [" << this->_name << "] displays a positive high fives" << '\n';
}