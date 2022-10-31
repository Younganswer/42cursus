/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:50:19 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 13:59:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	// std::cout << "MateriaSource constructor called\n";
	this->_count = 0;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref) {
	// std::cout << "MateriaSource copy constructor called\n";
	*this = ref;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &ref) {
	// std::cout << "MateriaSource copy assignation operator called\n";
	if (this != &ref) {
		this->_count = ref._count;
		for (int i=0; i<4; i++)
			this->_materia[i] = ref._materia[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	// std::cout << "MateriaSource destructor called\n";
	for (int i=0; i<4; i++)
		delete this->_materia[i];
}

void	MateriaSource::learnMateria(AMateria *mat) {
	if (4 <= this->_count)
		return;
	this->_materia[this->_count++] = mat;
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	AMateria	*ret = NULL;
	
	for (int i=0; i<_count; i++) {
		if (this->_materia[i]->getType() == type) {
			ret = this->_materia[i]->clone();
			break;
		}
	}
	return (ret);
}