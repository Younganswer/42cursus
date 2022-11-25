/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:19:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 21:21:48 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
	std::cout << "Default constructor of SC4V-TP is called" << '\n';
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
	std::cout << "const std::string constructor of SC4V-TP is called" << '\n';
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap(const ScavTrap &scav_trap) {
	(*this) = scav_trap;
	std::cout << "Copy constructor of SC4V-TP is called" << '\n';
	return;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scav_trap) {
	if (this != &scav_trap) {
		ClapTrap::operator=(scav_trap);
	}
	std::cout << "Copy assign operator of SC4V-TP is called" << '\n';
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Destructor of SC4V-TP is called" << '\n';
	return;
}

void	ScavTrap::guardGate(void) {
	std::cout << "SC4V-TP [" << this->getName() << "] is now in Gate keeper mode" << '\n';
	return;
}