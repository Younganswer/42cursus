/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:58:59 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:51:13 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(const Cure &ref) { (*this) = ref; }
Cure::~Cure(void) {}

Cure	&Cure::operator=(const Cure &ref) {
	if (this != &ref) {
		this->_type = ref._type.c_str();
		this->_xp = ref._xp;
	}
	return (*this);
}

// Utils
AMateria	*Cure::clone(void) const { return (new Cure(*this)); }
void		Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	this->_xp += 10;
}