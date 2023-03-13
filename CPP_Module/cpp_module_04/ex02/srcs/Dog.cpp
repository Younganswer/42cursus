#include "../incs/Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal("Dog") {
	std::cout << "Dog default constructor called" << '\n';
	this->_brain = new Brain();
}
Dog::Dog(const Dog &ref) {
	std::cout << "Dog copy constructor called" << '\n';
	(*this) = ref;
}
Dog::~Dog(void) {
	std::cout << "Dog destructor called" << '\n';
	delete this->_brain;
}

Dog	&Dog::operator=(const Dog &ref) {
	std::cout << "Dog copy assignation operator called" << '\n';
	if (this != &ref) {
		this->_type = ref._type;
		delete this->_brain;
		this->_brain = new Brain(*ref._brain);
	}
	return (*this);
}

// Util
void	Dog::makeSound(void) const { std::cout << "Woof woof!" << '\n'; }