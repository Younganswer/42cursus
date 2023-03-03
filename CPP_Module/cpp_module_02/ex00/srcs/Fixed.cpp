#include "../incs/Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _raw_bits(0) { std::cout << "Default constructor called" << '\n'; }

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << '\n';
	(*this) = fixed;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << '\n'; }

Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &fixed) {
		this->_raw_bits = fixed._raw_bits;
	}
	return (*this);
}

// Getter
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << '\n';
	return (this->_raw_bits);
}

// Setter
void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << '\n';
	this->_raw_bits = raw;
	return;
}