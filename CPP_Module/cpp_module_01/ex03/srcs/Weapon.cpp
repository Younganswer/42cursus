/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:32:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/09 23:38:02 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Weapon.hpp"

Weapon::Weapon(void) {
	type = std::string();
	return;
}

Weapon::Weapon(const std::string type) {
	this->type = type.c_str();
	return;
}

Weapon::Weapon(const Weapon &weapon) {
	*this = weapon;
	return;
}

Weapon	&Weapon::operator=(const Weapon &weapon) {
	this->type = weapon.type.c_str();
	return (*this);
}

Weapon::~Weapon(void) {
	return;
}

std::string	Weapon::getType(void) {
	return (type);
}

bool		Weapon::setType(const std::string &type) {
	this->type = type.c_str();
	return (true);
}