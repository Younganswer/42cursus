#include "../incs/Cat.hpp"
#include <iostream>

Cat::Cat(void): Animal("Cat") { std::cout << "Cat default constructor called" << '\n'; }
Cat::Cat(const Cat &ref) { std::cout << "Cat copy constructor called" << '\n'; (*this) = ref; }
Cat::~Cat(void) { std::cout << "Cat destructor called" << '\n'; }

Cat	&Cat::operator=(const Cat &ref) {
	std::cout << "Cat copy assignation operator called" << '\n';
	if (this != &ref) {
		this->_type = ref._type;
	}
	return (*this);
}

// Util
void	Cat::makeSound(void) const { std::cout << "Meow~" << '\n'; }