/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:22:47 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 18:43:08 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap(), _name(std::string()) {
	std::cout << "Default constructor of DiamonTrap is called\n";
	return;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_trap"), ScavTrap(name + "_scav_trap"), FragTrap(name + "_frag_trap") {
	std::cout << "const std::string constructor of DiamonTrap is called\n";
	this->_name = name.c_str();
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond_trap): ClapTrap(diamond_trap.getName() + "_clap_trap"), ScavTrap(diamond_trap.getName() + "_scav_trap"), FragTrap(diamond_trap.getName() + "_frag_trap") {
	(*this) = diamond_trap;
	std::cout << "Copy constructor of DiamonTrap is called\n";
	return;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamond_trap) {
	this->_name = diamond_trap.getName().c_str();
	std::cout << "Copy assign operator of DiamonTrap is called\n";
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "Destructor of DiamondTrap is called\n";
	return;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap's name is [" << this->_name << "]\n";
	std::cout << "ClapTrap's name is [" << this->getName() << "]\n";
	return;
}