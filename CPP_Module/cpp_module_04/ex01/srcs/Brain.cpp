/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:41:13 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/27 11:42:27 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << '\n';
}

Brain::Brain(const Brain &ref) {
	std::cout << "Brain copy constructor called" << '\n';
	*this = ref;
}

Brain	&Brain::operator=(const Brain& ref) {
	std::cout << "Brain copy assignation operator called" << '\n';
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ref.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << '\n';
}

std::string	*Brain::getIdeas(void) const {
	return ((std::string *)this->ideas);
}