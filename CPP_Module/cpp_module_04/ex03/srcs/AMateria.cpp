/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:11:34 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 12:55:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AMateria.hpp"

AMateria::AMateria(void): _type(std::string()), _xp(0) {
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const std::string &type): _type(type.c_str()), _xp(0) {
	std::cout << "AMateria constructor called\n";
}

AMateria::AMateria(const AMateria &ref) {
	*this = ref;
	std::cout << "AMateria copy constructor called\n";
}

AMateria	&AMateria::operator=(const AMateria &ref) {
	std::cout << "AMateria copy assignation operator called\n";
	if (this != &ref) {
		this->_type = ref._type.c_str();
		this->_xp = ref._xp;
	}
	return (*this);
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called\n";
}

const std::string	&AMateria::getType(void) const {
	return (this->_type);
}

unsigned int		AMateria::getXP(void) const {
	return (this->_xp);
}

void				AMateria::use(ICharacter &target) {
	(void) target;
	this->_xp += 10;
}