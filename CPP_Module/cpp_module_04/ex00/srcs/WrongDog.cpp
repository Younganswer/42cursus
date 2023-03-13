#include "../incs/WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void): WrongAnimal("WrongDog") { std::cout << "WrongDog default constructor called" << '\n'; }
WrongDog::WrongDog(const WrongDog &ref) { std::cout << "WrongDog copy constructor called" << '\n'; (*this) = ref; }
WrongDog::~WrongDog(void) { std::cout << "WrongDog destructor called" << '\n'; }

WrongDog	&WrongDog::operator=(const WrongDog &ref) {
	std::cout << "WrongDog copy assignation operator called" << '\n';
	this->_type = ref._type.c_str();
	return (*this);
}

// Util
void	WrongDog::makeSound(void) const { std::cout << "Woof woof!" << '\n'; }