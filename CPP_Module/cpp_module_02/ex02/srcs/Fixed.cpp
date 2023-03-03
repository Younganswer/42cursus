#include "../incs/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _raw_bits(0) {}
Fixed::Fixed(const int raw) { this->_raw_bits = (raw << _fractional_bits); }
Fixed::Fixed(const float raw) { this->_raw_bits = roundf(raw * (1 << _fractional_bits)); }
Fixed::Fixed(const Fixed &fixed) { (*this) = fixed; }
Fixed::~Fixed(void) {}
Fixed	&Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed) {
		this->_raw_bits = fixed._raw_bits;
	}
	return (*this);
}

// Getter
int		Fixed::getRawBits(void) const { return (this->_raw_bits); }

// Setter
void	Fixed::setRawBits(const int raw) { this->_raw_bits = raw; }

// Utils
int			Fixed::toInt(void) const { return (this->_raw_bits >> _fractional_bits); }
float		Fixed::toFloat(void) const { return ((float)this->_raw_bits / (1 << _fractional_bits)); }
Fixed		&Fixed::min(Fixed &fixed1, Fixed &fixed2) { return ((fixed1._raw_bits < fixed2._raw_bits) ? fixed1 : fixed2); }
Fixed		&Fixed::max(Fixed &fixed1, Fixed &fixed2) { return ((fixed1._raw_bits > fixed2._raw_bits) ? fixed1 : fixed2); }
const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2) { return ((fixed1._raw_bits < fixed2._raw_bits) ? fixed1 : fixed2); }
const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2) { return ((fixed1._raw_bits > fixed2._raw_bits) ? fixed1 : fixed2); }

// Operator Overload
bool	Fixed::operator<(const Fixed &rhs) const { return (this->_raw_bits < rhs._raw_bits); }
bool	Fixed::operator>(const Fixed &rhs) const { return (this->_raw_bits > rhs._raw_bits); }
bool	Fixed::operator<=(const Fixed &rhs) const { return (this->_raw_bits <= rhs._raw_bits); }
bool	Fixed::operator>=(const Fixed &rhs) const { return (this->_raw_bits >= rhs._raw_bits); }
bool	Fixed::operator==(const Fixed &rhs) const { return (this->_raw_bits == rhs._raw_bits); }
bool	Fixed::operator!=(const Fixed &rhs) const { return (this->_raw_bits != rhs._raw_bits); }
Fixed	Fixed::operator+(const Fixed &rhs) const { return (Fixed(this->toFloat() + rhs.toFloat())); }
Fixed	Fixed::operator-(const Fixed &rhs) const { return (Fixed(this->toFloat() - rhs.toFloat())); }
Fixed	Fixed::operator*(const Fixed &rhs) const { return (Fixed(this->toFloat() * rhs.toFloat())); }
Fixed	Fixed::operator/(const Fixed &rhs) const {
	if (rhs.toInt() == 0) {
		throw std::runtime_error("zero division error");
	}
	return (Fixed(this->toFloat() / rhs.toFloat()));
}
Fixed	Fixed::operator++(int) {
	Fixed	fixed(*this);
	this->_raw_bits++;
	return (fixed);
}
Fixed	&Fixed::operator++(void) {
	++(this->_raw_bits);
	return (*this);
}

// toString
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}