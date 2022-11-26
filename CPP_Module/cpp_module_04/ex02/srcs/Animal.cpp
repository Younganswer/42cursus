/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:20:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:39:18 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"

Animal::Animal(void): _type("Animal") { std::cout << "Animal default constructor called" << '\n'; }
Animal::Animal(const std::string &type): _type(type) { std::cout << "Animal (const std::string &type) constructor called" << '\n'; }
Animal::Animal(const Animal &ref) { std::cout << "Animal copy constructor called" << '\n'; (*this) = ref; }
Animal::~Animal(void) { std::cout << "Animal destructor called" << '\n'; }

Animal	&Animal::operator=(const Animal& ref) {
	std::cout << "Animal copy assignation operator called" << '\n';
	this->_type = ref._type.c_str();
	return (*this);
}

// Getter
std::string			Animal::getType(void) { return (this->_type); }
const std::string	&Animal::getType(void) const { return (this->_type); }

// Util
void	Animal::makeSound(void) const { std::cout << "Animal makeSound called" << '\n'; }