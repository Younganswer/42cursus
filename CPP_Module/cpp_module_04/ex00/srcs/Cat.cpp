/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:25:40 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:22:00 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(void): Animal("Cat") { std::cout << "Cat default constructor called" << '\n'; }
Cat::Cat(const Cat &ref) { std::cout << "Cat copy constructor called" << '\n'; (*this) = ref; }
Cat::~Cat(void) { std::cout << "Cat destructor called" << '\n'; }

Cat	&Cat::operator=(const Cat &ref) {
	std::cout << "Cat copy assignation operator called" << '\n';
	this->_type = ref._type.c_str();
	return (*this);
}

// Util
void	Cat::makeSound(void) const { std::cout << "Meow~" << '\n'; }