/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:35:15 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 00:01:35 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanA.hpp"

HumanA::HumanA(void) {
	weapon = NULL;
	name = std::string();
	return;
}

HumanA::HumanA(const std::string &name, Weapon &weapon) {
	this->weapon = &weapon;
	this->name.clear();
	this->name.append(name);
	return;
}

HumanA::HumanA(const HumanA &humanA) {
	(*this) = humanA;
	return;
}

HumanA	&HumanA::operator=(const HumanA &humanA) {
	*(this->weapon) = *(humanA.weapon);
	this->name.clear();
	this->name.append(humanA.name);
	return (*this);
}

HumanA::~HumanA(void) {
	return;
}

bool	HumanA::attack(void) {
	std::cout << name << " attacks with their " << weapon->getType() << '\n';
	return (true);
}

bool	HumanA::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	return (true);
}