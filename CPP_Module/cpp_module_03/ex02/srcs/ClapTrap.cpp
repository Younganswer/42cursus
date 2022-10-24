/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:08:56 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/24 11:43:48 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap(void): name(std::string()), hit_points(10), energy_points(0), attack_damage(0) {
	std::cout << "Default constructor of ClapTrap is called\n";
	return;
}

ClapTrap::ClapTrap(const std::string &name): name(name.c_str()), hit_points(10), energy_points(0), attack_damage(0) {
	std::cout << "const std::string constructor of ClapTrap is called\n";
	return;
}

ClapTrap::ClapTrap(const ClapTrap &clap_trap) {
	std::cout << "Copy constructor of ClapTrap is called\n";
	if (this != &clap_trap)
		(*this) = clap_trap;
	return;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clap_trap) {
	std::cout << "Copy assignment operator of ClapTrap is called\n";
	if (this != &clap_trap) {
		this->name = clap_trap.name.c_str();
		this->hit_points = clap_trap.hit_points;
		this->energy_points = clap_trap.energy_points;
		this->attack_damage = clap_trap.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor of ClapTrap is called\n";
	return;
}

void	ClapTrap::attack(const std::string &target) {
	if (!energy_points || !hit_points)
		return;
	energy_points--;
	std::cout << '[' << name << "] attacks [" << target << "], causing [" << attack_damage << "] points of damage!\n";
	return;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points <= amount) {
		std::cout << '[' << name << "] is run out of its hit points\n";
		hit_points = 0;
		return;
	}
	std::cout << '[' << name << "] took [" <<  amount << "] damage!\n";
	hit_points -= amount;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!energy_points || !hit_points)
		return;
	energy_points--;
	std::cout << '[' << name << "] is repaired: Restore [" << amount << "] hit points\n";
	hit_points += amount;
	return;
}

std::string		ClapTrap::getName(void) {
	return (name);
}

unsigned int	ClapTrap::getHitPoints(void) {
	return (hit_points);
}

unsigned int	ClapTrap::getEnergePoints(void) {
	return (energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) {
	return (attack_damage);
}

void	ClapTrap::setName(const std::string &name) {
	this->name = name.c_str();
	return;
}

void	ClapTrap::setHitPoints(unsigned int amount) {
	hit_points = amount;
	return;
}

void	ClapTrap::setEnergePoints(unsigned int amount) {
	energy_points = amount;
	return;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	attack_damage = amount;
	return;
}