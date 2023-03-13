#include "../incs/Animal.hpp"
#include <iostream>

Animal::Animal(void): _type("Animal") { std::cout << "Animal default constructor called" << '\n'; }
Animal::Animal(const std::string &type): _type(type) {
	std::cout << "Animal const std::string reference constructor called" << '\n';
}
Animal::Animal(const Animal &ref) {
	std::cout << "Animal copy constructor called" << '\n';
	(*this) = ref;
}
Animal::~Animal(void) { std::cout << "Animal destructor called" << '\n'; }

Animal	&Animal::operator=(const Animal& ref) {
	std::cout << "Animal copy assignation operator called" << '\n';
	if (this != &ref) {
		this->_type = ref._type;
	}
	return (*this);
}

// Getter
std::string			Animal::getType(void) { return (this->_type); }
const std::string	&Animal::getType(void) const { return (this->_type); }

// Util
void	Animal::makeSound(void) const { std::cout << "Animal makeSound called" << '\n'; }