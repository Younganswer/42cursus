/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:19:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/22 17:18:53 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	std::cout << "Default constructor of FragTrap is called\n";
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
	return;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
	std::cout << "const std::string constructor of FragTrap is called\n";
	this->setHitPoints(100);
	this->setEnergePoints(50);
	this->setAttackDamage(20);
	return;
}

FragTrap::FragTrap(const FragTrap &Frag_trap) {
	if (this == &Frag_trap)
		return;
	(*this) = Frag_trap;
	std::cout << "Copy constructor of FragTrap is called\n";
	return;
}

FragTrap	&FragTrap::operator=(const FragTrap &Frag_trap) {
	if (this == &Frag_trap)
		return (*this);
	ClapTrap::operator=(Frag_trap);
	std::cout << "Copy assign operator of FragTrap is called\n";
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "Destructor of FragTrap is called\n";
	return;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << '[' << this->getName() << "] displays a positive high fives\n";
	return;
}