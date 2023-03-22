#include "../incs/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _raw_bits(0) {
	std::cout << "Default constructor called" << '\n';
}
Fixed::Fixed(const int raw): _raw_bits(raw << this->_fractional_bits) {
	std::cout << "Const int constructor called" << '\n';
}
Fixed::Fixed(const float raw): _raw_bits(roundf(raw * (1 << this->_fractional_bits))) {
	std::cout << "Const float constructor called" << '\n';
}
Fixed::Fixed(const Fixed &fixed): _raw_bits(fixed._raw_bits) {
	std::cout << "Copy constructor called" << '\n';
}
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << '\n';
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &fixed) {
		this->~Fixed();
		new (this) Fixed(fixed);
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
}

// Utils
int		Fixed::toInt(void) const { return (this->_raw_bits >> this->_fractional_bits); }
float	Fixed::toFloat(void) const { return ((float)this->_raw_bits / (1 << this->_fractional_bits)); }

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}