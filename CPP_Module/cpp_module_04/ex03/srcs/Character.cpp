/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:42:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:50:11 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"

Character::Character(void) {
	this->_name = "default";
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}
Character::Character(const std::string &name) {
	this->_name = name.c_str();
	for (int i=0; i<4; i++) {
		this->_inventory[i] = NULL;
	}
}
Character::Character(const Character &ref) { (*this) = ref; }
Character::~Character(void) {
	for (int i=0; i<4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
}

Character	&Character::operator=(const Character &ref) {
	if (this != &ref) {
		this->_name = ref._name.c_str();
		for (int i=0; i<4; i++) {
			this->_inventory[i] = ref._inventory[i];
		}
	}
	return (*this);
}

// Getter
std::string			Character::getName(void) { return (this->_name); }
const std::string	&Character::getName(void) const { return (this->_name); }

// Utils
void	Character::equip(AMateria *mat) {
	if (mat == NULL || mat->getEquipped()) {
		return;
	}

	for (int i=0; i<4; i++) {
		if (this->_inventory[i] == NULL) {
			mat->setEquipped(true);
			this->_inventory[i] = mat;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if ((idx < 0 || 3 < idx) || (this->_inventory[idx] == NULL)) {
		return;
	}
	
	this->_inventory[idx]->setEquipped(false);
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if ((idx < 0 || 3 < idx) || this->_inventory[idx] == NULL) {
		return;
	}

	this->_inventory[idx]->use(target);
}