/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:32:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/08 23:38:29 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Weapon.hpp"

Weapon::Weapon(void) {
	type = std::string();
	return;
}

Weapon::Weapon(const std::string type) {
	this->type.clear();
	this->type.append(type);
	return;
}

Weapon::Weapon(const Weapon &weapon) {
	*this = weapon;
	return;
}

Weapon	&Weapon::operator=(const Weapon &weapon) {
	this->type.clear();
	this->type.append(weapon.type);
	return (*this);
}

Weapon::~Weapon(void) {
	return;
}

std::string	Weapon::getType(void) {
	return (type);
}

bool		Weapon::setType(const std::string &type) {
	this->type.clear();
	this->type.append(type);
	return (true);
}