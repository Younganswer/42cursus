/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:52:00 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 14:07:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Floor.hpp"

Floor::Floor(void) {
	_count = 0;
	for (int i=0; i<1024; i++)
		this->_materia[i] = NULL;
}

Floor::Floor(const Floor &ref) {
	(*this) = ref;
}

Floor& Floor::operator=(const Floor &ref) {
	if (this != &ref) {
		this->_count = ref._count;
		for (size_t i=0; i<_count; i++) {
			this->_materia[i] = ref._materia[i];
		}
	}
	return (*this);
}

Floor::~Floor() {
	for (size_t i=0; i<_count; i++) {
		if (this->_materia[i]->getEquipped() == false)
			delete this->_materia[i];
	}
}

//	Getter
AMateria* Floor::getMateria(size_t idx) {
	if (idx < 0 || _count <= idx)
		return (NULL);

	return (this->_materia[idx]);
}

//	Setter
void Floor::setMateria(AMateria *materia) {
	if (1024 <= _count)
		return ;
	_materia[_count++] = materia;
}