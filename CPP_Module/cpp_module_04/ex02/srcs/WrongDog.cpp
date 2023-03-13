#include "../incs/WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void): WrongAnimal("WrongDog") {
	std::cout << "WrongDog default constructor called" << '\n';
	this->_brain = new Brain();	
}
WrongDog::WrongDog(const WrongDog &ref) {
	std::cout << "WrongDog copy constructor called" << '\n';
	(*this) = ref;
}
WrongDog::~WrongDog(void) {
	std::cout << "WrongDog destructor called" << '\n';
	delete this->_brain;
}

WrongDog	&WrongDog::operator=(const WrongDog &ref) {
	std::cout << "WrongDog copy assignation operator called" << '\n';
	if (this != &ref) {
		this->_type = ref._type;
		delete this->_brain;
		this->_brain = new Brain(*ref._brain);
	}
	return (*this);
}

// Util
void	WrongDog::makeSound(void) const { std::cout << "Woof woof!" << '\n'; }