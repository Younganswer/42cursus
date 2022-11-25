/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:08:56 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 21:22:48 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name(std::string()), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Default constructor of CL4P-TP is called" << '\n';
	return;
}

ClapTrap::ClapTrap(const std::string &name): _name(std::string(name.c_str())), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "const std::string constructor of CL4P-TP is called" << '\n';
	return;
}

ClapTrap::ClapTrap(const ClapTrap &clap_trap) {
	std::cout << "Copy constructor of CL4P-TP is called" << '\n';
	(*this) = clap_trap;
	return;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clap_trap) {
	std::cout << "Copy assignment operator of CL4P-TP is called" << '\n';
	if (this != &clap_trap) {
		this->_name = std::string(clap_trap._name.c_str());
		this->_hit_points = clap_trap._hit_points;
		this->_energy_points = clap_trap._energy_points;
		this->_attack_damage = clap_trap._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor of CL4P-TP is called" << '\n';
	return;
}

void	ClapTrap::attack(const std::string &target) {
	if (!this->_energy_points || !this->_hit_points)
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

// Getters
std::string		ClapTrap::getName(void) {
	return (this->_name);
}

const std::string	&ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergePoints(void) const {
	return (this->_energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_attack_damage);
}

void	ClapTrap::setHitPoints(unsigned int amount) {
	this->_hit_points = amount;
	return;
}

void	ClapTrap::setName(const std::string &name) {
	this->_name = name.c_str();
	return;
}

void	ClapTrap::setEnergePoints(unsigned int amount) {
	this->_energy_points = amount;
	return;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attack_damage = amount;
	return;
}