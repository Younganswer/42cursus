#include "../incs/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap() {
	std::cout << "Default constructor of SC4V-TP is called" << '\n';
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
	std::cout << "const std::string reference constructor of SC4V-TP is called" << '\n';
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
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
void	ScavTrap::guardGate(void) {
	std::cout << "SC4V-TP [" << this->getName() << "] is now in Gate keeper mode" << '\n';
}