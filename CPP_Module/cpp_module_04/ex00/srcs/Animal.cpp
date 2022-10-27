/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:20:03 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:51:30 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Animal.hpp"

Animal::Animal(void): type("Animal") {
	std::cout << "Animal default constructor called" << '\n';
}

Animal::Animal(const std::string &type): type(type) {
	std::cout << "Animal (const std::string &type) constructor called" << '\n';
}


Animal::Animal(const Animal &ref) {
	std::cout << "Animal copy constructor called" << '\n';
	*this = ref;
}

Animal	&Animal::operator=(const Animal& ref) {
	std::cout << "Animal copy assignation operator called" << '\n';
	this->type = ref.type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << '\n';
}

void	Animal::makeSound(void) const {
	std::cout << "Animal makeSound called" << '\n';
}

std::string	Animal::getType(void) const {
	return (this->type);
}