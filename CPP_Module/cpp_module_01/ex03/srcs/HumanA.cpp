/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:35:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/25 20:22:48 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanA.hpp"

HumanA::HumanA(void) {
	this->_weapon = NULL;
	this->_name = std::string();
	return;
}

HumanA::HumanA(const std::string &name, Weapon &weapon) {
	this->_weapon = &weapon;
	this->_name = std::string(name.c_str());
	return;
}

HumanA::HumanA(const HumanA &humanA) {
	(*this) = humanA;
	return;
}

HumanA	&HumanA::operator=(const HumanA &humanA) {
	if (this != &humanA) {
		this->_weapon = humanA._weapon;
		this->_name = std::string(humanA._name.c_str());
	}
	return (*this);
}

HumanA::~HumanA(void) {}

bool	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '\n';
	return (true);
}

bool	HumanA::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	return (true);
}