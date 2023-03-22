#include "../incs/Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal("Dog") {
	std::cout << "Dog default constructor called" << '\n';
}
Dog::Dog(const Dog &ref): Animal(ref) {
	std::cout << "Dog copy constructor called" << '\n';
}
Dog::~Dog(void) {
	std::cout << "Dog destructor called" << '\n';
}

Dog	&Dog::operator=(const Dog &rhs) {
	std::cout << "Dog copy assignation operator called" << '\n';
	if (this != &rhs) {
		this->~Dog();
		new (this) Dog(rhs);
	}
	return (*this);
}

// Util
void	Dog::makeSound(void) const { std::cout << "Woof woof!" << '\n'; }