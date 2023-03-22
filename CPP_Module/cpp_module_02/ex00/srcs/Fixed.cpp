#include "../incs/Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _raw_bits(0) {
	std::cout << "Default constructor called" << '\n';
}
Fixed::Fixed(const Fixed &ref): _raw_bits(ref._raw_bits) {
	std::cout << "Copy constructor called" << '\n';
}
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << '\n';
}

Fixed	&Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &rhs) {
		this->~Fixed();
		new (this) Fixed(rhs);
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