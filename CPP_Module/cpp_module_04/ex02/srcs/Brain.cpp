#include "../incs/Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << '\n';
	for (int i=0; i<100; i++) {
		this->_ideas[i] = "";
	}
}
Brain::Brain(const Brain &ref) {
	std::cout << "Brain copy constructor called" << '\n';
	for (int i=0; i<100; i++) {
		this->_ideas[i] = ref._ideas[i];
	}
}
Brain::~Brain(void) {
	std::cout << "Brain destructor called" << '\n';
}

Brain	&Brain::operator=(const Brain &rhs) {
	std::cout << "Brain copy assignation operator called" << '\n';
	if (this != &rhs) {
		this->~Brain();
		new (this) Brain(rhs);
	}
	return (*this);
}

// Getter
const std::string	&Brain::getIdea(int index) const { return (this->_ideas[index]); }

// Setter
bool	Brain::setIdea(int idx, const std::string &idea) {
	if (0 <= idx && idx < 100) {
		this->_ideas[idx] = idea;
	}
	return (true);
}