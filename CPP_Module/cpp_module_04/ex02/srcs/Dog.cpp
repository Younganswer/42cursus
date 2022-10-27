/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:23:54 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:44:47 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	std::cout << "Dog default constructor called" << '\n';
	this->brain = new Brain();
}

Dog::Dog(const Dog &ref) {
	std::cout << "Dog copy constructor called" << '\n';
	*this = ref;
}

Dog	&Dog::operator=(const Dog &ref) {
	std::cout << "Dog copy assignation operator called" << '\n';
	this->type = ref.type;
	delete this->brain;
	this->brain = new Brain(*ref.brain);
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << '\n';
	delete this->brain;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof woof!" << '\n';
}