/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:35:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 23:40:47 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanB.hpp"

HumanB::HumanB(void) {
	weapon = NULL;
	name = std::string();
	return;
}

HumanB::HumanB(const std::string &name) {
	weapon = NULL;
	this->name = name.c_str();
	return;
}

HumanB::HumanB(const std::string &name, Weapon &weapon) {
	this->weapon = &weapon;
	this->name = name.c_str();
	return;
}

HumanB::HumanB(const HumanB &humanB) {
	(*this) = humanB;
	return;
}

HumanB	&HumanB::operator=(const HumanB &humanB) {
	*(this->weapon) = *(humanB.weapon);
	this->name = humanB.name.c_str();
	return (*this);
}

HumanB::~HumanB(void) {
	return;
}

bool	HumanB::attack(void) {
	std::cout << name << " attacks with their " << weapon->getType() << '\n';
	return (true);
}

bool	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	return (true);
}