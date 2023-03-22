#include "../incs/WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void): WrongAnimal("WrongDog"), _brain(new Brain) {
	std::cout << "WrongDog default constructor called" << '\n';
}
WrongDog::WrongDog(const WrongDog &ref): WrongAnimal(ref), _brain(new Brain(*ref._brain)) {
	std::cout << "WrongDog copy constructor called" << '\n';
}
WrongDog::~WrongDog(void) {
	std::cout << "WrongDog destructor called" << '\n';
	delete this->_brain;
}

WrongDog	&WrongDog::operator=(const WrongDog &rhs) {
	std::cout << "WrongDog copy assignation operator called" << '\n';
	if (this != &rhs) {
		this->~WrongDog();
		new (this) WrongDog(rhs);
	}
	return (*this);
}

// Util
void	WrongDog::makeSound(void) const { std::cout << "Woof woof!" << '\n'; }