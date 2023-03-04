#include "../incs/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _name(std::string()), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Default constructor of CL4P-TP is called" << '\n';
}
ClapTrap::ClapTrap(const std::string &name): _name(name.c_str()), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Const std::string reference constructor of CL4P-TP is called" << '\n';
}
ClapTrap::ClapTrap(const ClapTrap &clap_trap) {
	std::cout << "Copy constructor of CL4P-TP is called" << '\n';
	(*this) = clap_trap;
}
ClapTrap::~ClapTrap(void) { std::cout << "Destructor of CL4P-TP is called" << '\n'; }

ClapTrap	&ClapTrap::operator=(const ClapTrap &clap_trap) {
	std::cout << "Copy assignment operator of CL4P-TP is called" << '\n';
	if (this != &clap_trap) {
		this->_name = clap_trap._name.c_str();
		this->_hit_points = clap_trap._hit_points;
		this->_energy_points = clap_trap._energy_points;
		this->_attack_damage = clap_trap._attack_damage;
	}
	return (*this);
}

// Utils
void	ClapTrap::attack(const std::string &target) {
	if (this->_hit_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (this->_energy_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its energy points" << '\n';
	} else {
		std::cout << "CL4P-TP [" << this->_name << "] attacks [" << target << "], causing [" << this->_attack_damage << "] points of damage!" << '\n';
		this->_energy_points--;
	}
	return;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (this->_hit_points <= amount) {
		std::cout << "CL4P-TP [" << this->_name << "] took [" <<  this->_hit_points << "] damage!" << '\n';
		this->_hit_points = 0;
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else {
		std::cout << "CL4P-TP [" << this->_name << "] took [" <<  amount << "] damage!" << '\n';
		this->_hit_points -= amount;
		std::cout << "CL4P-TP [" << this->_name << "] has [" << this->_hit_points << "] hit points left" << '\n';
	}
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
	} else if (this->_energy_points == 0) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its energy points" << '\n';
	} else {
		std::cout << "CL4P-TP [" << this->_name << "] is repaired: Restore [" << amount << "] hit points" << '\n';
		this->_hit_points += amount;
		std::cout << "CL4P-TP [" << this->_name << "] has [" << this->_hit_points << "] hit points" << '\n';
		this->_energy_points--;
	}
	return;
}