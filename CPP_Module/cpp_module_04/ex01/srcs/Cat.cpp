#include "../incs/Cat.hpp"
#include <iostream>

Cat::Cat(void): Animal("Cat"), _brain(new Brain) {
	std::cout << "Cat default constructor called" << '\n';
}
Cat::Cat(const Cat &ref): Animal(ref), _brain(new Brain(*ref._brain)) {
	std::cout << "Cat copy constructor called" << '\n';
}
Cat::~Cat(void) {
	std::cout << "Cat destructor called" << '\n';
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat &rhs) {
	std::cout << "Cat copy assignation operator called" << '\n';
	if (this != &rhs) {
		this->~Cat();
		new (this) Cat(rhs);
	}
	return (*this);
}

// Util
void	Cat::makeSound(void) const { std::cout << "Meow~" << '\n'; }