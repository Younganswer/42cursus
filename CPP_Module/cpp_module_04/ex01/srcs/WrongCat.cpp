#include "../incs/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal("WrongCat"), _brain(new Brain) {
	std::cout << "WrongCat default constructor called" << '\n';
}
WrongCat::WrongCat(const WrongCat &ref): WrongAnimal(ref), _brain(new Brain(*ref._brain)) {
	std::cout << "WrongCat copy constructor called" << '\n';
}
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << '\n';
	delete this->_brain;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs) {
	std::cout << "WrongCat copy assignation operator called" << '\n';
	if (this != &rhs) {
		this->~WrongCat();
		new (this) WrongCat(rhs);
	}
	return (*this);
}

// Util
void	WrongCat::makeSound(void) const { std::cout << "Meow~" << '\n'; }