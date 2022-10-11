/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:51 by younhwan          #+#    #+#             */
/*   Updated: 2022/10/11 14:27:23 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed {
private:
	static const int	fractional_bits = 8;
	int					raw_bits;

public:
	Fixed(void);
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &fixed);
	Fixed	&operator=(const Fixed &fixed);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator<(const Fixed &rhs) const;
	bool	operator>(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;
	Fixed	operator++(int);
	Fixed	&operator++(void);

	static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);


#endif