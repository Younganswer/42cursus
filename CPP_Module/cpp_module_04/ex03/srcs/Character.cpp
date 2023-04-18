#include "../incs/Character.hpp"

Character::Character(void): _name("Default") {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}
Character::Character(const std::string &name): _name(name) {
	for (int i=0; i<4; i++) {
		this->_inventory[i] = NULL;
	}
}
Character::Character(const Character &ref): _name(ref._name) {
	for (int i=0; i<4; i++) {
		if (ref._inventory[i]) {
			this->_inventory[i] = ref._inventory[i]->clone();
		}
	}
}
Character::~Character(void) {
	for (int i=0; i<4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
}

Character	&Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		this->~Character();
		new (this) Character(rhs);
	}
	return (*this);
}

// Getter
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