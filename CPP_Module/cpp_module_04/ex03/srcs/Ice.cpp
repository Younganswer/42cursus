/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:51:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:53:43 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ice.hpp"

Ice::Ice(void): AMateria("ice") {}
Ice::Ice(const std::string &type): AMateria(type) {}
Ice::Ice(const Ice &ref) { (*this) = ref; }
Ice::~Ice(void) {}

Ice	&Ice::operator=(const Ice &ref) {
	// std::cout << "Ice copy assignation operator called\n";
	if (this != &ref) {
		this->_type = ref._type.c_str();
		this->_xp = ref._xp;
	}
	return (*this);
}

// Utils
AMateria	*Ice::clone(void) const { return (new Ice(*this)); }
void		Ice::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}