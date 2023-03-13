#include "../incs/Brain.hpp"
#include <iostream>

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

// Setter
bool	Brain::setIdea(int idx, const std::string &idea) {
	if (0 <= idx && idx < 100) {
		this->_ideas[idx] = idea;
	}
	return (true);
}