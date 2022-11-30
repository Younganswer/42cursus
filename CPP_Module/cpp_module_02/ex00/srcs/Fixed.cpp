/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:25:08 by younhwan          #+#    #+#             */
/*   Updated: 2022/11/30 16:37:43 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

Fixed::Fixed(void): _raw_bits(0) {
	std::cout << "Default constructor called" << '\n';
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