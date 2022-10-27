/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:25:40 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:31:06 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cat.hpp"

Cat::Cat(void): Animal("Cat") {
	std::cout << "Cat default constructor called" << '\n';
}

Cat::Cat(const Cat &ref) {
	std::cout << "Cat copy constructor called" << '\n';
	*this = ref;
}

Cat	&Cat::operator=(const Cat &ref) {
	std::cout << "Cat copy assignation operator called" << '\n';
	this->type = ref.type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << '\n';
}

void	Cat::makeSound(void) const {
	std::cout << "Meow~" << '\n';
}