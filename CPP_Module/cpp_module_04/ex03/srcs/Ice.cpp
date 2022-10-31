/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:51:04 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/31 12:11:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ice.hpp"

Ice::Ice(void): AMateria("ice") {
	// std::cout << "Ice default constructor called\n";
}

Ice::Ice(const std::string &type): AMateria(type) {
	// std::cout << "Ice constructor called\n";
}

Ice::Ice(const Ice &ref) {
	*this = ref;
	// std::cout << "Ice copy constructor called\n";
}

Ice	&Ice::operator=(const Ice &ref) {
	// std::cout << "Ice copy assignation operator called\n";
	if (this != &ref) {
		this->_type = ref._type.c_str();
		this->_xp = ref._xp;
	}
	return (*this);
}

Ice::~Ice(void) {
	// std::cout << "Ice destructor called\n";
}

AMateria	*Ice::clone(void) const {
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}