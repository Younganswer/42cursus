/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:25:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/11 14:39:31 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

Fixed::Fixed(void): raw_bits(0) {
	// std::cout << "Default constructor called\n";
	return;
}

Fixed::Fixed(const int raw) {
	// std::cout << "Int constructor called\n";
	raw_bits = (raw << fractional_bits);
	return;
}

Fixed::Fixed(const float raw) {
	// std::cout << "Float constructor called\n";
	raw_bits = roundf(raw * (1 << fractional_bits));
	return;
}

Fixed::Fixed(const Fixed &fixed) {
	// std::cout << "Copy constructor called\n";
	if (this != &fixed)
		this->raw_bits = fixed.raw_bits;
	return;
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	// std::cout << "Copy assignment operator called\n";
	if (this != &fixed)
		this->raw_bits = fixed.raw_bits;
	return (*this);
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called\n";
	return;
}

int		Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called\n";
	return (raw_bits);
}

void	Fixed::setRawBits(const int raw) {
	// std::cout << "setRawBits member function called\n";
	this->raw_bits = raw;
	return;
}

int		Fixed::toInt(void) const {
	return (raw_bits >> fractional_bits);
}

float	Fixed::toFloat(void) const {
	return ((float)raw_bits / (1 << fractional_bits));
}

bool	Fixed::operator<(const Fixed &rhs) const {
	return (raw_bits < rhs.raw_bits);
}

bool	Fixed::operator>(const Fixed &rhs) const {
	return (raw_bits > rhs.raw_bits);
}

bool	Fixed::operator<=(const Fixed &rhs) const {
	return (raw_bits <= rhs.raw_bits);
}

bool	Fixed::operator>=(const Fixed &rhs) const {
	return (raw_bits >= rhs.raw_bits);
}

bool	Fixed::operator==(const Fixed &rhs) const {
	return (raw_bits == rhs.raw_bits);
}

bool	Fixed::operator!=(const Fixed &rhs) const {
	return (raw_bits != rhs.raw_bits);
}

Fixed	Fixed::operator+(const Fixed &rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const {
	if (!rhs.toInt())
		throw std::runtime_error("zero division error");
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator++(int) {
	Fixed	fixed(*this);
	raw_bits++;
	return (fixed);
}

Fixed	&Fixed::operator++(void) {
	++this->raw_bits;
	return (*this);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	return ((fixed1.raw_bits < fixed2.raw_bits) ? fixed1 : fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	return ((fixed1.raw_bits < fixed2.raw_bits) ? fixed1 : fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	return ((fixed1.raw_bits > fixed2.raw_bits) ? fixed1 : fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	return ((fixed1.raw_bits > fixed2.raw_bits) ? fixed1 : fixed2);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}