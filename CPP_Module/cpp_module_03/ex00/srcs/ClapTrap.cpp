/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:08:56 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 16:01:06 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap(void): name(std::string()), hit_points(10), energy_points(0), attack_damage(0) {
	std::cout << "Default constructor called\n";
	return;
}

ClapTrap::ClapTrap(const std::string name): name(name.c_str()), hit_points(10), energy_points(0), attack_damage(0) {
	std::cout << "std::string constructor called\n";
	return;
}

ClapTrap::ClapTrap(const ClapTrap &clap_trap) {
	std::cout << "Copy constructor called\n";
	if (this != &clap_trap)
		(*this) = clap_trap;
	return;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clap_trap) {
	std::cout << "Copy assignment operator called\n";
	if (this != &clap_trap) {
		this->name = clap_trap.name.c_str();
		this->hit_points = clap_trap.hit_points;
		this->energy_points = clap_trap.energy_points;
		this->attack_damage = clap_trap.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called\n";
	return;
}

void	ClapTrap::attack(ClapTrap &target) {
	if (!energy_points)
		return;
	energy_points--;
	std::cout << "ClapTrap [" << name << "] attacks [" << target.name << "], causing [" << attack_damage << "] points of damage!\n";
	target.takeDamage(attack_damage);
	return;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points <= amount) {
		std::cout << "Claptrap [" << name << "] is run out of its hit points\n";
		hit_points = 0;
		return;
	}
	std::cout << "Claptrap [" << name << "] took " <<  amount << " damage!\n";
	hit_points -= amount;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!energy_points)
		return;
	energy_points--;
	std::cout << "Claptrap [" << name << "] regained " << amount << " of its hit points ";
	hit_points += amount;
	return;
}

void	ClapTrap::setAttackDamage(unsigned int amount) {
	attack_damage = amount;
	return;
}

unsigned int	ClapTrap::getAttackDamage(void) {
	return (attack_damage);
}

void	ClapTrap::setEnergePoint(unsigned int amount) {
	energy_points = amount;
	return;
}

unsigned int	ClapTrap::getEnergePoint(void) {
	return (energy_points);
}