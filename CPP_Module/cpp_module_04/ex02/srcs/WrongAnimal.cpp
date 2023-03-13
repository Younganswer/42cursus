#include "../incs/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") { std::cout << "WrongAnimal default constructor called" << '\n'; }
WrongAnimal::WrongAnimal(const std::string &type): _type(type) {
	std::cout << "WrongAnimal const std::string reference constructor called" << '\n';
}
WrongAnimal::WrongAnimal(const WrongAnimal &ref) {
	std::cout << "WrongAnimal copy constructor called" << '\n';
	(*this) = ref;
}
WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal destructor called" << '\n'; }

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& ref) {
	std::cout << "WrongAnimal copy assignation operator called" << '\n';
	if (this != &ref) {
		this->_type = ref._type;
	}
	return (*this);
}

// Getter
std::string			WrongAnimal::getType(void) { return (this->_type); }
const std::string	&WrongAnimal::getType(void) const { return (this->_type); }

// Util
void	WrongAnimal::makeSound(void) const { std::cout << "WrongAnimal makeSound called" << '\n'; }