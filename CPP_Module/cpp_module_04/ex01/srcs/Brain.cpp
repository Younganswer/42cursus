/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:41:13 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/26 12:31:50 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Brain.hpp"

Brain::Brain(void) { std::cout << "Brain default constructor called" << '\n'; }
Brain::Brain(const Brain &ref) { std::cout << "Brain copy constructor called" << '\n'; (*this) = ref; }
Brain::~Brain(void) { std::cout << "Brain destructor called" << '\n'; }

Brain	&Brain::operator=(const Brain& ref) {
	std::cout << "Brain copy assignation operator called" << '\n';
	for (int i=0; i<100; i++) {
		this->_ideas[i] = ref._ideas[i];
	}
	return (*this);
}

// Getter
std::string			Brain::getIdea(int index) { return (this->_ideas[index]); }
const std::string	&Brain::getIdea(int index) const { return (this->_ideas[index]); }