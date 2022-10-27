/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:58:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 12:59:57 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure constructor called\n";
}

Cure::Cure(const Cure &ref) {
	std::cout << "Cure copy constructor called\n";
	*this = ref;
}

Cure	&Cure::operator=(const Cure &ref) {
	std::cout << "Cure copy assignation operator called\n";
	if (this != &ref) {
		this->_type = ref._type.c_str();
		this->_xp = ref._xp;
	}
	return (*this);
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called\n";
}

AMateria	*Cure::clone(void) const {
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	this->_xp += 10;
}