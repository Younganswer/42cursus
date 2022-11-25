/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:32:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 00:01:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Weapon.hpp"

Weapon::Weapon(void) {
	this->_type = std::string();
	return;
}

Weapon::Weapon(const std::string &type) {
	this->_type = std::string(type.c_str());
	return;
}

Weapon::Weapon(const Weapon &weapon) {
	*this = weapon;
	return;
}

Weapon	&Weapon::operator=(const Weapon &weapon) {
	if (this != &weapon) {
		this->_type = std::string(weapon._type.c_str());
	}
	return (*this);
}

Weapon::~Weapon(void) {}

std::string	Weapon::getType(void) {
	return (this->_type);
}

bool		Weapon::setType(const std::string &type) {
	this->_type = std::string(type.c_str());
	return (true);
}