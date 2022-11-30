/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:25:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/30 16:42:44 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

Fixed::Fixed(void): _raw_bits(0) {
	std::cout << "Default constructor called" << '\n';
	return;
}

Fixed::Fixed(const int raw) {
	std::cout << "Int constructor called" << '\n';
	this->_raw_bits = raw << this->_fractional_bits;
	return;
}

Fixed::Fixed(const float raw) {
	std::cout << "Float constructor called" << '\n';
	this->_raw_bits = roundf(raw * (1 << this->_fractional_bits));
	return;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << '\n';
	(*this) = fixed;
	return;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << '\n';
	return;
}

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

// Utils
int		Fixed::toInt(void) const { return (this->_raw_bits >> this->_fractional_bits); }
float	Fixed::toFloat(void) const { return ((float)this->_raw_bits / (1 << this->_fractional_bits)); }

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}