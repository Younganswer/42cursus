#include "../incs/DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap(), _name(std::string()) {
	std::cout << "Default constructor of DiamonTrap is called" << '\n';
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap") {
	std::cout << "const std::string constructor of DiamonTrap is called" << '\n';
	this->_name = name.c_str();
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond_trap): ClapTrap(diamond_trap._name + "_clap_trap"), ScavTrap(diamond_trap._name + "_clap_trap"), FragTrap(diamond_trap._name + "_clap_trap") {
	std::cout << "Copy constructor of DiamonTrap is called" << '\n';
	(*this) = diamond_trap;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamond_trap) {
	std::cout << "Copy assign operator of DiamonTrap is called" << '\n';
	if (this != &diamond_trap) {
		ClapTrap::operator=(diamond_trap);
		this->_name = diamond_trap._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) { std::cout << "Destructor of DiamondTrap is called" << '\n'; }

unsigned int	DiamondTrap::getAttackDamage(void) const { return (FragTrap::_attack_damage); }

void	DiamondTrap::attack(const std::string &target) {
	if (FragTrap::_hit_points == 0) {
		std::cout << "DI4MOND-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (ScavTrap::_energy_points == 0) {
		std::cout << "DI4MOND-TP [" << this->_name << "] is run out of its energy points" << '\n';
	} else {
		ScavTrap::attack(target);
	}
	return;
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	if (FragTrap::_hit_points == 0) {
		std::cout << "DI4MOND-TP [" << this->_name << "] is run out of its hit points" << '\n';
		std::cout << "DI4MOND-TP [" << this->_name << "] takes [" << FragTrap::_hit_points << "] damage" << '\n';
		FragTrap::_hit_points = 0;
		std::cout << "DI4MOND-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else {
		std::cout << "DI4MOND-TP [" << this->_name << "] takes [" << amount << "] damage" << '\n';
		FragTrap::_hit_points -= amount;
		std::cout << "DI4MOND-TP [" << this->_name << "] has [" << FragTrap::_hit_points << "] hit points left" << '\n';
	}
	return;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (FragTrap::_hit_points == 0) {
		std::cout << "DI4MOND-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (ScavTrap::_energy_points == 0) {
		std::cout << "DI4MOND-TP [" << this->_name << "] is run out of its energy points" << '\n';
	} else {
		std::cout << "DI4MOND-TP [" << this->_name << "] is repaired: Restore [" << amount << "] hit points" << '\n';
		FragTrap::_hit_points += amount;
		std::cout << "DI4MOND-TP [" << this->_name << "] has [" << FragTrap::_hit_points << "] hit points" << '\n';
	}
	return;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap's name is [" << this->_name << "]" << '\n';
	std::cout << "ClapTrap's name is [" << ClapTrap::_name << "]" << '\n';
	return;
}