/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:19:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/24 12:17:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	std::cout << "Default constructor of FR4G-TP is called\n";
	this->setHitPoints(100);
	this->setAttackDamage(30);
	return;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
	std::cout << "const std::string constructor of FR4G-TP is called\n";
	this->setHitPoints(100);
	this->setAttackDamage(30);
	return;
}

FragTrap::FragTrap(const FragTrap &Frag_trap) {
	if (this == &Frag_trap)
		return;
	(*this) = Frag_trap;
	std::cout << "Copy constructor of FR4G-TP is called\n";
	return;
}

FragTrap	&FragTrap::operator=(const FragTrap &Frag_trap) {
	if (this == &Frag_trap)
		return (*this);
	ClapTrap::operator=(Frag_trap);
	std::cout << "Copy assign operator of FR4G-TP is called\n";
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "Destructor of FR4G-TP is called\n";
	return;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FR4G-TP [" << this->getName() << "] gives a high five to all the guys\n";
	return;
}