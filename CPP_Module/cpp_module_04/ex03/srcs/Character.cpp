/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:42:36 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 12:35:14 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"

Character::Character(void) {
	// std::cout << "Default Character constructor called\n";
	this->_name = "default";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name) {
	// std::cout << "Character (const std::string &name) constructor called\n";
	this->_name = name.c_str();
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &ref) {
	// std::cout << "Character copy constructor called\n";
	*this = ref;
}

Character	&Character::operator=(const Character &ref) {
	// std::cout << "Character copy assignation operator called\n";
	if (this != &ref) {
		this->_name = ref._name.c_str();
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = ref._inventory[i];
	}
	return (*this);
}

Character::~Character(void) {
	// std::cout << "Character destructor called\n";
	for (int i=0; i<4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

const std::string	&Character::getName(void) const {
	return (this->_name);
}

void	Character::equip(AMateria *mat) {
	if (mat->getEquipped())
		return ;

	for (int i=0; i<4; i++) {
		if (this->_inventory[i] == NULL) {
			mat->setEquipped(true);
			this->_inventory[i] = mat;
			break;
		}
	}
	return;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	this->_inventory[idx]->setEquipped(false);
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return;
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}