#include "../incs/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << '\n';
}
WrongAnimal::WrongAnimal(const std::string &type): _type(type) {
	std::cout << "WrongAnimal const std::string reference constructor called" << '\n';
}
WrongAnimal::WrongAnimal(const WrongAnimal &ref): _type(ref._type) {
	std::cout << "WrongAnimal copy constructor called" << '\n';
}
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << '\n';
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << "WrongAnimal copy assignation operator called" << '\n';
	if (this != &rhs) {
		this->~WrongAnimal();
		new (this) WrongAnimal(rhs);
	}
	return (*this);
}

// Getter
std::string			WrongAnimal::getType(void) { return (this->_type); }
const std::string	&WrongAnimal::getType(void) const { return (this->_type); }

// Util
void	WrongAnimal::makeSound(void) const { std::cout << "WrongAnimal makeSound called" << '\n'; }