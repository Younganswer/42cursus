/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:50:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:56:36 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	this->_count = 0;
	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}
MateriaSource::MateriaSource(const MateriaSource &ref) { (*this) = ref; }
MateriaSource::~MateriaSource(void) {
	for (int i=0; i<4; i++) {
		delete this->_materia[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &ref) {
	if (this != &ref) {
		this->_count = ref._count;
		for (int i=0; i<4; i++) {
			this->_materia[i] = ref._materia[i];
		}
	}
	return (*this);
}

// Utils
void	MateriaSource::learnMateria(AMateria *mat) {
	if (4 <= this->_count) {
		return;
	}
	this->_materia[this->_count++] = mat;
}
AMateria	*MateriaSource::createMateria(const std::string &type) const {
	for (int i=0; i<_count; i++) {
		if (this->_materia[i]->getType() == type) {
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}