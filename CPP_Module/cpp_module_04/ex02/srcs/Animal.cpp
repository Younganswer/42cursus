#include "../incs/Animal.hpp"
#include <iostream>

Animal::Animal(void): _type("Animal") {
	std::cout << "Animal default constructor called" << '\n';
}
Animal::Animal(const std::string &type): _type(type) {
	std::cout << "Animal const std::string reference constructor called" << '\n';
}
Animal::Animal(const Animal &ref): _type(ref._type) {
	std::cout << "Animal copy constructor called" << '\n';
}
Animal::~Animal(void) {
	std::cout << "Animal destructor called" << '\n';
}

Animal	&Animal::operator=(const Animal& ref) {
	std::cout << "Animal copy assignation operator called" << '\n';
	(void) ref;
	return (*this);
}

// Getter
const std::string	&Animal::getType(void) const { return (this->_type); }