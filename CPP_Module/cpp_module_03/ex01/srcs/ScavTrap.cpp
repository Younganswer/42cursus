/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:19:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 17:05:49 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
	std::cout << "Default constructor of ScavTrap is called\n";
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
	std::cout << "const std::string constructor of ScavTrap is called\n";
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap(const ScavTrap &scav_trap) {
	if (this == &scav_trap)
		return;
	(*this) = scav_trap;
	std::cout << "Copy constructor of ScavTrap is called\n";
	return;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scav_trap) {
	if (this == &scav_trap)
		return (*this);
	ClapTrap::operator=(scav_trap);
	std::cout << "Copy assign operator of ScavTrap is called\n";
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Destructor of ScavTrap is called\n";
	return;
}

void	ScavTrap::guardGate(void) {
	std::cout << '[' << this->getName() << "] is now in Gate keeper mode\n";
	return;
}