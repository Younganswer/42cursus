/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:23:54 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:22:49 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(void): Animal("Dog") { std::cout << "Dog default constructor called" << '\n'; }
Dog::Dog(const Dog &ref) { std::cout << "Dog copy constructor called" << '\n'; (*this) = ref; }
Dog::~Dog(void) { std::cout << "Dog destructor called" << '\n'; }

Dog	&Dog::operator=(const Dog &ref) {
	std::cout << "Dog copy assignation operator called" << '\n';
	this->_type = ref._type.c_str();
	return (*this);
}

// Util
void	Dog::makeSound(void) const { std::cout << "Woof woof!" << '\n'; }