#include "../incs/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): _name(std::string()), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Default constructor of CL4P-TP is called" << '\n';
}
ClapTrap::ClapTrap(const std::string &name): _name(name.c_str()), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "const std::string reference constructor of CL4P-TP is called" << '\n';
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


// Getter
std::string			ClapTrap::getName(void) { return (this->_name); }
const std::string	&ClapTrap::getName(void) const { return (this->_name); }
unsigned int		ClapTrap::getHitPoints(void) const { return (this->_hit_points); }
unsigned int		ClapTrap::getEnergePoints(void) const { return (this->_energy_points); }
unsigned int		ClapTrap::getAttackDamage(void) const { return (this->_attack_damage); }

// Setter
bool	ClapTrap::setHitPoints(unsigned int amount) {
	this->_hit_points = amount;
	return (true);	
}
bool	ClapTrap::setName(const std::string &name) {
	this->_name = name.c_str();
	return (true);
}
bool	ClapTrap::setEnergePoints(unsigned int amount) {
	this->_energy_points = amount;
	return (true);
}
bool	ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attack_damage = amount;
	return (true);
}

// Utils
void	ClapTrap::attack(const std::string &target) {
	if (this->_energy_points == 0 || this->_hit_points == 0)
		return;
	this->_energy_points--;
	std::cout << "CL4P-TP [" << this->_name << "] attacks [" << target << "], causing [" << this->_attack_damage << "] points of damage!" << '\n';
	return;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= amount) {
		std::cout << "CL4P-TP [" << this->_name << "] is run out of its hit points" << '\n';
		this->_hit_points = 0;
		return;
	}
	std::cout << "CL4P-TP [" << this->_name << "] took [" <<  amount << "] damage!" << '\n';
	this->_hit_points -= amount;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points == 0 || this->_hit_points == 0)
		return;
	this->_energy_points--;
	std::cout << "CL4P-TP [" << this->_name << "] is repaired: Restore [" << amount << "] hit points" << '\n';
	this->_hit_points += amount;
	return;
}