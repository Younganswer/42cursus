/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:25:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/10 14:43:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

Fixed::Fixed(void): raw_bits(0) {
	std::cout << "Default constructor called\n";	
	return;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called\n";
	this->raw_bits = fixed.raw_bits;
	return;
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called\n";
	this->raw_bits = fixed.raw_bits;
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
	return;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (raw_bits);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called\n";
	this->raw_bits = raw;
	return;
}