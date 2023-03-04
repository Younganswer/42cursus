#include "../incs/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap() {
	std::cout << "Default constructor of SC4V-TP is called" << '\n';
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
	std::cout << "const std::string reference constructor of SC4V-TP is called" << '\n';
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav_trap) {
	std::cout << "Copy constructor of SC4V-TP is called" << '\n';
	(*this) = scav_trap;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scav_trap) {
	std::cout << "Copy assign operator of SC4V-TP is called" << '\n';
	if (this != &scav_trap) {
		ClapTrap::operator=(scav_trap);
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) { std::cout << "Destructor of SC4V-TP is called" << '\n'; }

// Util
void	ScavTrap::attack(const std::string &target) {
	if (this->_hit_points == 0) {
		std::cout << "SC4V-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (this->_energy_points == 0) {
		std::cout << "SC4V-TP [" << this->_name << "] is run out of its energy points" << '\n';
	} else {
		std::cout << "SC4V-TP [" << this->_name << "] attacks [" << target << "], causing [" << this->_attack_damage << "] points of damage!" << '\n';
		this->_energy_points--;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "SC4V-TP [" << this->_name << "] is now in Gate keeper mode" << '\n';
}