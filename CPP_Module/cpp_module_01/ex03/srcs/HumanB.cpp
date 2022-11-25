/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:35:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:23:37 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanB.hpp"

HumanB::HumanB(void) {
	this->_weapon = NULL;
	this->_name = std::string();
	return;
}

HumanB::HumanB(const std::string &name) {
	this->_weapon = NULL;
	this->_name = std::string(name.c_str());
	return;
}

HumanB::HumanB(const std::string &name, Weapon &weapon) {
	this->_weapon = &weapon;
	this->_name = std::string(name.c_str());
	return;
}

HumanB::HumanB(const HumanB &humanB) {
	(*this) = humanB;
	return;
}

HumanB	&HumanB::operator=(const HumanB &humanB) {
	if (this != &humanB) {
		this->_weapon = humanB._weapon;
		this->_name = std::string(humanB._name.c_str());
	}
	return (*this);
}

HumanB::~HumanB(void) {}

bool	HumanB::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '\n';
	return (true);
}

bool	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	return (true);
}